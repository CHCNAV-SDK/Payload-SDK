/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal.c
 ********************************************************************************/
#include "osal.h"
#include "limits.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "stdlib.h"

#define SEM_MUTEX_WAIT_FOREVER      0xFFFFFFFF
#define TASK_PRIORITY_DEFAULT        0

chcnav_return_code_t osal_task_create(const char *name, void *(*task_func)(void *),
										uint32_t stack_size, void *arg, chcnav_task_handle_t *task)
{
	uint32_t stack_depth;
	char task_name[16] = {0};

	//attention :  freertos use stack depth param, stack size = (stack depth) * sizeof(StackType_t)
	if (stack_size % sizeof(StackType_t) == 0) {
		stack_depth = stack_size / sizeof(StackType_t);
	} else {
		stack_depth = stack_size / sizeof(StackType_t) + 1;
	}

    if (name != NULL)
		strncpy(task_name, name, sizeof(task_name) - 1);
	if (xTaskCreate((TaskFunction_t)task_func, task_name, stack_depth, arg, TASK_PRIORITY_DEFAULT, (TaskHandle_t *)task) != pdPASS) {
		*task = NULL;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_task_destroy(chcnav_task_handle_t task)
{
	if (task == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	vTaskDelete(task);
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_task_sleep_ms(uint32_t time_ms)
{
	TickType_t ticks;

	ticks = time_ms / portTICK_PERIOD_MS;
	vTaskDelay(ticks ? ticks : 1);
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_create(chcnav_mutex_handle_t *mutex)
{
	if (mutex == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	*mutex = xSemaphoreCreateMutex();
	if (*mutex == NULL) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_destroy(chcnav_mutex_handle_t mutex)
{
	if (mutex == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	vQueueDelete((SemaphoreHandle_t) mutex);
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_lock(chcnav_mutex_handle_t mutex)
{
	TickType_t ticks;

	if (mutex == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	ticks = portMAX_DELAY;

	if (xSemaphoreTake(mutex, ticks) != pdTRUE) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_unlock(chcnav_mutex_handle_t mutex)
{
	if (mutex == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	if (xSemaphoreGive(mutex) != pdTRUE) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_create(uint32_t init_value, chcnav_semaphore_handle_t *semaphore)
{
	uint32_t max_count = UINT_MAX;

	if (semaphore == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	*semaphore = xSemaphoreCreateCounting(max_count, init_value);

	if (*semaphore == NULL) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_destroy(chcnav_semaphore_handle_t semaphore)
{
	if (semaphore == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	vSemaphoreDelete(semaphore);
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_wait(chcnav_semaphore_handle_t semaphore)
{
	if (semaphore == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	if (xSemaphoreTake(semaphore, SEM_MUTEX_WAIT_FOREVER) != pdTRUE) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_timed_wait(chcnav_semaphore_handle_t semaphore, uint32_t wait_time_ms)
{
	TickType_t ticks;

	if (semaphore == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	ticks = 0;
	if (wait_time_ms == SEM_MUTEX_WAIT_FOREVER) {
		ticks = portMAX_DELAY;
	} else if (wait_time_ms != 0) {
		ticks = wait_time_ms / portTICK_PERIOD_MS;
		if (ticks == 0) {
			ticks = 1;
		}
	}
	if (xSemaphoreTake(semaphore, ticks) != pdTRUE) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_post(chcnav_semaphore_handle_t semaphore)
{
	if (semaphore == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	if (xSemaphoreGive(semaphore) != pdTRUE) {
		return CHCNAV_RETURN_ERR_SYSTEM;
	}
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_get_time_ms(uint32_t *ms)
{
	if (ms == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	*ms = xTaskGetTickCount();
	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_get_time_us(uint64_t *us)
{
	if (us == NULL) {
		return CHCNAV_RETURN_ERR_PARAM;
	}

	*us = xTaskGetTickCount() * 1000;
	return CHCNAV_RETURN_OK;
}

void *osal_malloc(uint32_t size)
{
	//return pvPortMalloc(size);
	return malloc(size);
}

void osal_free(void *ptr)
{
	//vPortFree(ptr);
	free(ptr);
}