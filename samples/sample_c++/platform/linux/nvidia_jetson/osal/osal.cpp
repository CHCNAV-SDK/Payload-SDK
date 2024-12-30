/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal.cpp
 ********************************************************************************/
#include "osal.h"
#include "chcnav_error.h"
#include "chcnav_typedef.h"

chcnav_return_code_t osal_task_create(const char *name,
                                      void *(*task_func)(void *),
                                      uint32_t stack_size, void *arg,
                                      chcnav_task_handle_t *task)
{
    int result;
    char thread_name[16] = {0};

    *task = malloc(sizeof(pthread_t));
    if (*task == nullptr) {
        return CHCNAV_RETURN_ERR_ALLOC;
    }

    result = pthread_create((pthread_t *)(*task), nullptr, task_func, arg);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    if (name != nullptr){
        strncpy(thread_name, name, sizeof(thread_name) - 1);
    }
    result = pthread_setname_np(*(pthread_t*)(*task), thread_name);
    if (result != 0) {
        printf("set thread name[%s] failed:%d\n", name, result);
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_task_destroy(chcnav_task_handle_t task)
{
    if(task != nullptr) {
        pthread_join(*(pthread_t *)task,nullptr);
        free(task);
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_task_sleep_ms(uint32_t time_ms)
{
    usleep(1000 * time_ms);

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_create(chcnav_mutex_handle_t *mutex)
{
    int result;

    if (!mutex) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    *mutex = malloc(sizeof(pthread_mutex_t));
    if (*mutex == nullptr) {
        return CHCNAV_RETURN_ERR_ALLOC;
    }

    result = pthread_mutex_init((pthread_mutex_t*)(*mutex), nullptr);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_destroy(chcnav_mutex_handle_t mutex)
{
    int result = 0;

    if (!mutex) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    result = pthread_mutex_destroy((pthread_mutex_t *)mutex);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }
    free(mutex);

    return CHCNAV_RETURN_OK;
}


chcnav_return_code_t osal_mutex_lock(chcnav_mutex_handle_t mutex)
{
    int result = 0;

    if (!mutex) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    result = pthread_mutex_lock((pthread_mutex_t *)mutex);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_mutex_unlock(chcnav_mutex_handle_t mutex)
{
    int result = 0;

    if (!mutex) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    result = pthread_mutex_unlock((pthread_mutex_t *)mutex);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}


chcnav_return_code_t osal_semaphore_create(
      uint32_t init_value, chcnav_semaphore_handle_t *semaphore){
    int result;

    *semaphore = malloc(sizeof(sem_t));
    if (*semaphore == nullptr) {
        return
            CHCNAV_RETURN_ERR_ALLOC;
    }

    result = sem_init((sem_t *)*semaphore, 0, (unsigned int) init_value);
    if (result != 0) {
        return
            CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}


chcnav_return_code_t osal_semaphore_destroy(
      chcnav_semaphore_handle_t semaphore)
{
    int result;

    result = sem_destroy((sem_t *) semaphore);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    free(semaphore);

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_wait(chcnav_semaphore_handle_t semaphore)
{
    int result;

    result = sem_wait((sem_t *)semaphore);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_timed_wait(
      chcnav_semaphore_handle_t semaphore, uint32_t wait_time_ms){
    int result;
    struct timespec semaphore_wait_time;
    struct timeval systemTime;

    gettimeofday(&systemTime, nullptr);

    systemTime.tv_usec += wait_time_ms * 1000;
    if (systemTime.tv_usec >= 1000000) {
        systemTime.tv_sec += systemTime.tv_usec / 1000000;
        systemTime.tv_usec %= 1000000;
    }

    semaphore_wait_time.tv_sec = systemTime.tv_sec;
    semaphore_wait_time.tv_nsec = systemTime.tv_usec * 1000;

    result = sem_timedwait((sem_t *)semaphore, &semaphore_wait_time);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_semaphore_post(chcnav_semaphore_handle_t semaphore)
{
    int result;

    result = sem_post((sem_t *)semaphore);
    if (result != 0) {
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}


chcnav_return_code_t osal_get_time_ms(uint32_t *ms)
{
    struct timeval time;

    gettimeofday(&time, nullptr);
    *ms = (time.tv_sec * 1000 + time.tv_usec / 1000);

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_get_time_us(uint64_t *us)
{
    struct timeval time;

    gettimeofday(&time, nullptr);
    *us = (time.tv_sec * 1000000 + time.tv_usec);

    return CHCNAV_RETURN_OK;
}


void *osal_malloc(uint32_t size)
{
    return malloc(size);
}

void osal_free(void *ptr)
{
    free(ptr);
}
