#include "chcnav_core.h"
#include "chcnav_error.h"
#include "chcnav_logger.h"
#include "hal/hal_network.h"
#include "hal/hal_uart.h"
#include "osal/osal.h"
#include "osal/osal_fs.h"
#include "osal/osal_socket.h"
#include "test_camera_manager.h"
#include "test_payload_camera.h"
#include "test_gimbal_manager.h"
#include "test_gimbal.h"
#include "test_fc_subscription.h"
#include "test_widget.h"
#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <signal.h>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <unistd.h>

bool g_stop = false;
static FILE *g_log_file = nullptr;

void signal_handler(int signal) {
  (void)signal;
  g_stop = true;
}

static chcnav_return_code_t user_print_console(const uint8_t *data, uint16_t data_len)
{
  if (data == nullptr || data_len == 0) {
    return CHCNAV_RETURN_ERR_PARAM;
  }
  (void)fwrite(data, 1, data_len, stdout);
  (void)fflush(stdout);
  return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t user_file_console(const uint8_t *data, uint16_t data_len)
{
  if (data == nullptr || data_len == 0 || g_log_file == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }
  size_t written = fwrite(data, 1, data_len, g_log_file);
  (void)fflush(g_log_file);
  return (written == data_len) ? CHCNAV_RETURN_OK : CHCNAV_RETURN_ERR_SYSTEM;
}

static chcnav_return_code_t user_log_file_init(const char *folder)
{
  char path[256];
  time_t now = time(nullptr);
  struct tm *lt = localtime(&now);

  if (folder == nullptr || lt == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }
  if (access(folder, F_OK) != 0) {
    if (mkdir(folder, 0755) != 0) {
      return CHCNAV_RETURN_ERR_SYSTEM;
    }
  }
  snprintf(path, sizeof(path), "%s/psdk_%04d%02d%02d_%02d-%02d-%02d.log", folder,
           lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min,
           lt->tm_sec);
  g_log_file = fopen(path, "wb+");
  if (g_log_file == nullptr) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t prepare_environment() {
  chcnav_return_code_t ret;
  CHCNAV_OSAL_HANDLER_STRUCT osal_handler_struct = {
      .task_create = osal_task_create,
      .task_destroy = osal_task_destroy,
      .task_sleep_ms = osal_task_sleep_ms,
      .mutex_create = osal_mutex_create,
      .mutex_destroy = osal_mutex_destroy,
      .mutex_lock = osal_mutex_lock,
      .mutex_unlock = osal_mutex_unlock,
      .semaphore_create = osal_semaphore_create,
      .semaphore_destroy = osal_semaphore_destroy,
      .semaphore_wait = osal_semaphore_wait,
      .semaphore_timed_wait = osal_semaphore_timed_wait,
      .semaphore_post = osal_semaphore_post,
      .get_time_ms = osal_get_time_ms,
      .get_time_us = osal_get_time_us,
      .malloc = osal_malloc,
      .free = osal_free};

  CHCNAV_HAL_UART_HANDLER_STRUCT hal_uart_handler_struct = {
      .uart_init = hal_uart_init,
      .uart_deinit = hal_uart_deinit,
      .uart_write_data = hal_uart_write_data,
      .uart_read_data = hal_uart_read_data,
      .uart_read_data_timeout = hal_uart_read_data_timeout,
      .uart_get_status = hal_uart_get_status};

  CHCNAV_HAL_NETWORK_HANDLER_STRUCT hal_network_handler_struct = {
      .network_init = hal_network_init,
      .network_deinit = hal_network_deinit,
      .network_get_device_info = hal_network_get_device_info};

  CHCNAV_FILE_SYSTEM_HANDLER_STRUCT osal_file_system_handler_struct = {
      .file_open = osal_file_open,
      .file_close = osal_file_close,
      .file_write = osal_file_write,
      .file_read = osal_file_read,
      .file_seek = osal_file_seek,
      .file_sync = osal_file_sync,
      .dir_open = osal_dir_open,
      .dir_close = osal_dir_close,
      .dir_read = osal_dir_read,
      .dir_create = osal_dir_create,
      .file_unlink = osal_file_unlink,
      .file_rename = osal_file_rename,
      .file_stat = osal_file_stat};

  CHCNAV_LOGGER_CONSOLE_STRUCT print_console = {
      .func = user_print_console,
      .console_level = CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_INFO,
  };
  CHCNAV_LOGGER_CONSOLE_STRUCT file_console = {
      .func = user_file_console,
      .console_level = CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_INFO,
  };

  ret = chcnav_platform_reg_osal_handler(&osal_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Register osal handler failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_platform_reg_hal_uart_handler(&hal_uart_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Register hal uart handler failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_platform_reg_hal_network_handler(&hal_network_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Register hal network handler failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret =
      chcnav_platform_reg_file_system_handler(&osal_file_system_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Register osal file system failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = user_log_file_init("psdk_logs");
  if (ret != CHCNAV_RETURN_OK) {
    printf("Init log file failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_logger_add_console(&print_console);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Add print logger console failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_logger_add_console(&file_console);
  if (ret != CHCNAV_RETURN_OK) {
    printf("Add file logger console failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  chcnav_return_code_t ret;
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  ret = prepare_environment();
  if (ret != CHCNAV_RETURN_OK) {
    printf("prepare environment failed");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  ret = chcnav_core_init();
  if (ret != CHCNAV_RETURN_OK) {
    CHCNAV_LOG_ERROR(demo, "chcnav_core_init failed");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  char moduleStr;
  while (true) {
    std::cout << "\n"
              << "| Choose your test module:                                           "
                 "                                           |\n"
              << "| [0] Run multi module hybrid test - you can test gimbal camera      "
                 " payload functions                         |\n"
              << "| [a] Run camera manager module sample - you can test camera control "
                 "functions interactively                    |\n"
              << "| [b] Run payload camera module sample - you can test camera's       "
                 "functions interactively                    |\n"
              << "| [c] Run gimbal manager module sample - you can test gimbal control "
                 "functions interactively                    |\n"
              << "| [d] Run gimbal module sample - you can test gimbal's               "
                 "functions interactively                    |\n"
              << "| [q] Quit test program                                              "
                 "                                           |\n"
              << std::endl;

    if (!(std::cin >> moduleStr)) {
      goto EXIT;
    }
    switch (moduleStr) {
    case 'q':
      printf("Quit...\n");
      goto EXIT;
    case '0': {
      char inputStr;
      chcnav_test_gimbal_start();
      chcnav_run_payload_camera_sample();
      chcnav_run_fc_subscription_sample();
      if (chcnav_test_widget_start() != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_WARN(demo, "chcnav_test_widget_start failed (continuing hybrid test)");
      }
      printf("input \'q\' to exit multi module hybrid test program\n");
      while (std::cin >> inputStr && inputStr != 'q') {
      }
      chcnav_test_widget_stop();
      chcnav_test_gimbal_stop();
      chcnav_stop_payload_camera_sample();
      chcnav_stop_fc_subscription_sample();
      if (!std::cin) {
        goto EXIT;
      }
      break;
    }
    case 'a':
      chcnav_run_camera_manager_sample();
      break;
    case 'b': {
      char inputStr;
      chcnav_run_payload_camera_sample();
      printf("input \'q\' to exit test  payload camera program\n");
      std::cin >> inputStr;
      if (inputStr == 'q')
      {
        chcnav_stop_payload_camera_sample();
      }
      break;
    }
    case 'c': {
      chcnav_run_gimbal_manager_sample();
      break;
    }
  
    case 'd': {
      char inputStr;
      ret = chcnav_test_gimbal_start();
      if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_test_gimbal_start failed");
        goto EXIT;
      }

      ret = chcnav_core_start();
      if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_core_start failed");
        goto EXIT;
      }
      printf("input \'q\' to exit gimbal test program\n");
      std::cin >> inputStr;
      if (inputStr == 'q')
      {
        chcnav_test_gimbal_stop();
      }
      break;
    }
    default:
      CHCNAV_LOG_ERROR(demo, "invalid input");
      break;
    }
  }

EXIT:
  chcnav_core_deinit();
  CHCNAV_LOG_INFO(demo, "chcnav psdk end");
  return 0;
}