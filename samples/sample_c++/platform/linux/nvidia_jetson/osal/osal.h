/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal.h
 * @brief This is the header file for "osal.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef CHCNAV_OSAL_H
#define CHCNAV_OSAL_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>
#include "chcnav_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t osal_task_create(const char *name,
                                      void *(*task_func)(void *),
                                      uint32_t stack_size, void *arg,
                                      chcnav_task_handle_t *task);
chcnav_return_code_t osal_task_destroy(chcnav_task_handle_t task);
chcnav_return_code_t osal_task_sleep_ms(uint32_t time_ms);

chcnav_return_code_t osal_mutex_create(chcnav_mutex_handle_t *mutex);
chcnav_return_code_t osal_mutex_destroy(chcnav_mutex_handle_t mutex);
chcnav_return_code_t osal_mutex_lock(chcnav_mutex_handle_t mutex);
chcnav_return_code_t osal_mutex_unlock(chcnav_mutex_handle_t mutex);

chcnav_return_code_t osal_semaphore_create(
      uint32_t init_value, chcnav_semaphore_handle_t *semaphore);
chcnav_return_code_t osal_semaphore_destroy(
      chcnav_semaphore_handle_t semaphore);
chcnav_return_code_t osal_semaphore_wait(chcnav_semaphore_handle_t semaphore);
chcnav_return_code_t osal_semaphore_timed_wait(
      chcnav_semaphore_handle_t semaphore, uint32_t wait_time_ms);
chcnav_return_code_t osal_semaphore_post(chcnav_semaphore_handle_t semaphore);

chcnav_return_code_t osal_get_time_ms(uint32_t *ms);
chcnav_return_code_t osal_get_time_us(uint64_t *us);

void *osal_malloc(uint32_t size);
void osal_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif