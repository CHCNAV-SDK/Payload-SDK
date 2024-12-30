#include "chcnav_core.h"
#include "chcnav_error.h"
#include "hal/hal_network.h"
#include "hal/hal_uart.h"
#include "osal/osal.h"
#include "osal/osal_fs.h"
#include "osal/osal_socket.h"
#include "test_camera_manager.h"
#include "test_payload_camera.h"
#include "test_gimbal_manager.h"
#include "test_gimbal.h"
#include <chrono>
#include <iostream>
#include <signal.h>
#include <string>
#include <thread>
bool g_stop = false;

void signal_handler(int signal) {
  (void)signal;
  g_stop = true;
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

  ret = chcnav_platform_reg_osal_handler(&osal_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "Register osal handler failed" << std::endl;
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_platform_reg_hal_uart_handler(&hal_uart_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "Register hal uart handler failed" << std::endl;
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret = chcnav_platform_reg_hal_network_handler(&hal_network_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "Register hal uart network failed" << std::endl;
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  ret =
      chcnav_platform_reg_file_system_handler(&osal_file_system_handler_struct);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "Register osal file system failed" << std::endl;
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
    std::cout << "prepare environment failed" << std::endl;
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  ret = chcnav_core_init();
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_core_init failed" << std::endl;
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  char moduleStr;
  while (true) {
    std::cout << "\n"
              << "| Choose your test module:                                   "
                 "                                      |\n"
              << "| [a] Run camera manager sample - you can test camera's "
                 "functions interactively                    |\n"
              << "| [b] Run payload camera sample - you can test camera's "
                 "functions interactively                    |\n"
              << "| [c] Run gimbal manager sample - you can test gimbal's "
                 "functions interactively                    |\n"
			  << "| [d] Run gimbal sample - you can test gimbal's "
			     "functions interactively                    |\n"
              << "| [q] Quit test program                                      "
                 "                                      |\n"
              << std::endl;

    std::cin >> moduleStr;
    switch (moduleStr) {
    case 'q':
      std::cout << "Quit..." << std::endl;
      goto EXIT;
    case 'a':
      chcnav_run_camera_manager_sample();
      break;
    case 'b': {
      char cameraStr;
      ret = chcnav::psdk::modules_sample::TestPayloadCamera::get_instance()
                .chcnav_test_payload_camera_start();
      if (ret != CHCNAV_RETURN_OK) {
        std::cout << "chcnav_test_payload_camera_start failed" << std::endl;
        goto EXIT;
      }

      ret = chcnav_core_start();
      if (ret != CHCNAV_RETURN_OK) {
        std::cout << "chcnav_core_start failed" << std::endl;
        goto EXIT;
      }
      std::cout << "input \'q\' to exit camera test program" << std::endl;
      std::cin >> cameraStr;
      if (cameraStr == 'q')
        goto EXIT;
      break;
    }
    case 'c':
      chcnav_run_gimbal_manager_sample();
      break;
    case 'd': {
      char gimbalStr;
      ret = chcnav_test_gimbal_start();
      std::cout << "chcnav_test_gimbal_start ret :" << ret << std::endl;
      if (ret != CHCNAV_RETURN_OK) {
        std::cout << "chcnav_test_gimbal_start failed" << std::endl;
        goto EXIT;
      }

      ret = chcnav_core_start();
      if (ret != CHCNAV_RETURN_OK) {
        std::cout << "chcnav_core_start failed" << std::endl;
        goto EXIT;
      }
      std::cout << "input \'q\' to exit gimbal test program" << std::endl;
      std::cin >> gimbalStr;
      if (gimbalStr == 'q')
        goto EXIT;
      break;
    }
    default:
      std::cout << "invalid input" << std::endl;
      break;
    }
  }

EXIT:
  chcnav_core_deinit();
  std::cout << "chcnav psdk end" << std::endl;
  return 0;
}