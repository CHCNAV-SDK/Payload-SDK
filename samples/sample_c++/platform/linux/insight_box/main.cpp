#include "chcnav_core.h"
#include "chcnav_error.h"
#include "chcnav_logger.h"
#include "hal/hal_network.h"
#include "hal/hal_uart.h"
#include "osal/osal.h"
#include "osal/osal_fs.h"
#include "osal/osal_socket.h"
#include "chcnav_camera_manager.h"
#include "chcnav_gimbal_manager.h"
#include <chrono>
#include <cstdio>
#include <ctime>
#include <cstring>
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

static void run_aibox_sample() {
  chcnav_return_code_t ret;
  CHCNAV_MOUNT_POSITION_E position = CHCNAV_MOUNT_POSITION_EXTENSION_PORT3;
  CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT rotate;
  while (!g_stop) {
    memset(&rotate, 0, sizeof(CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT));
    rotate.yaw = 0;
    rotate.roll = 0;
    rotate.pitch = 30.0;
    printf("--> Function: Set gimbal rotate:[%.1f %.1f %.1f]...\n", rotate.pitch, rotate.roll, rotate.yaw);
    ret = chcnav_gimbal_manager_rorate(position, rotate);
    if (ret != CHCNAV_RETURN_OK) {
      CHCNAV_LOG_ERROR(insight_box, "Set gimbal rotate failed:%d", ret);
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));

    memset(&rotate, 0, sizeof(CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT));
    rotate.yaw = 0;
    rotate.roll = 0;
    rotate.pitch = -30.0;
    printf("--> Function: Set gimbal rotate:[%.1f %.1f %.1f]...\n", rotate.pitch, rotate.roll, rotate.yaw);
    ret = chcnav_gimbal_manager_rorate(position, rotate);
    if (ret != CHCNAV_RETURN_OK) {
      CHCNAV_LOG_ERROR(insight_box, "Set gimbal rotate failed:%d", ret);
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));

    memset(&rotate, 0, sizeof(CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT));
    rotate.yaw = 30.0;
    rotate.roll = 0;
    rotate.pitch = 0;
    printf("--> Function: Set gimbal rotate:[%.1f %.1f %.1f]...\n", rotate.pitch, rotate.roll, rotate.yaw);
    ret = chcnav_gimbal_manager_rorate(position, rotate);
    if (ret != CHCNAV_RETURN_OK) {
      CHCNAV_LOG_ERROR(insight_box, "Set gimbal rotate failed:%d", ret);
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));

    memset(&rotate, 0, sizeof(CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT));
    rotate.yaw = -30.0;
    rotate.roll = 0;
    rotate.pitch = 0;
    printf("--> Function: Set gimbal rotate:[%.1f %.1f %.1f]...\n", rotate.pitch, rotate.roll, rotate.yaw);
    ret = chcnav_gimbal_manager_rorate(position, rotate);
    if (ret != CHCNAV_RETURN_OK) {
      CHCNAV_LOG_ERROR(insight_box, "Set gimbal rotate failed:%d", ret);
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  chcnav_return_code_t ret;
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  ret = prepare_environment();
  if (ret != CHCNAV_RETURN_OK) {
    printf("prepare environment failed\n");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  ret = chcnav_core_init();
  if (ret != CHCNAV_RETURN_OK) {
    CHCNAV_LOG_ERROR(insight_box, "chcnav_core_init failed");
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_gimbal_manager_init();
  if (ret != CHCNAV_RETURN_OK) {
    CHCNAV_LOG_ERROR(insight_box, "Init gimbal manager failed, error code: %d", ret);
    return CHCNAV_RETURN_OK;
  }
  run_aibox_sample();

  chcnav_gimbal_manager_deinit();
  chcnav_core_deinit();
  CHCNAV_LOG_INFO(insight_box, "chcnav psdk end");
  return 0;
}