/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file user_task.c
 * @brief This is the header file for "hal_uart.c".
 ********************************************************************************/
#include "user_task.h"
#include <stdio.h>
#include "test_payload_camera.h"
#include "test_gimbal.h"
#include "hal_uart.h"
#include "osal.h"

void chcnav_user_task(void const *argument)
{
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

	ret = chcnav_platform_reg_osal_handler(&osal_handler_struct);
	if (ret != CHCNAV_RETURN_OK) {
		printf("Register osal handler failed\n");
		goto out;
	}

	ret = chcnav_platform_reg_hal_uart_handler(&hal_uart_handler_struct);
	if (ret != CHCNAV_RETURN_OK) {
		printf("Register hal uart handler failed\n");
		goto out;
	}

	ret = chcnav_core_init();
	if (ret != CHCNAV_RETURN_OK) {
		printf("chcnav_core_init failed\n");
		goto out;
	}

	chcnav_run_payload_camera_sample();

	chcnav_test_gimbal_start();

	ret = chcnav_core_start();
		if (ret != CHCNAV_RETURN_OK) {
		goto out;
	}
	while(1)
	{
		osal_task_sleep_ms(500);
	}

out:
	vTaskDelete(xTaskGetCurrentTaskHandle());
}
