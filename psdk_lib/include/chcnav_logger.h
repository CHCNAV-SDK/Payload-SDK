/********************************************************************************
 * Copyright (c) 2025 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_logger.h
 * @brief Console-based log management for Payload SDK.
 ********************************************************************************/

#ifndef CHCNAV_LOGGER_H
#define CHCNAV_LOGGER_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CHCNAV_LOGGER_CONSOLE_MAX_NUM 8

/*! Max bytes of user log body after printf expansion (not including prefix). */
#define CHCNAV_LOGGER_MAX_USER_LOG_LEN 256

/**
 * @brief Logger console level.
 * @note Higher numeric value means more severe. A console receives messages whose
 *       level is greater than or equal to console_level.
 */
typedef enum {
    CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_DEBUG = 0,
    CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_INFO = 1,
    CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_WARN = 2,
    CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_ERROR = 3,
} CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E;

/**
 * @brief Console write callback.
 * @note data is a null-terminated formatted log line; data_len is byte length
 *       excluding the trailing '\0' (includes '\n' if present).
 */
typedef chcnav_return_code_t (*CHCNAV_LOGGER_CONSOLE_FUNC)(const uint8_t *data,
                                                           uint16_t data_len);

/**
 * @brief Logger console registration content.
 */
typedef struct {
    CHCNAV_LOGGER_CONSOLE_FUNC func;
    CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E console_level;
} CHCNAV_LOGGER_CONSOLE_STRUCT;

/**
 * @brief Add a console sink.
 * @note Maximum eight consoles. File logging, if needed, must be implemented
 *       inside the console callback by the application.
 */
chcnav_return_code_t chcnav_logger_add_console(const CHCNAV_LOGGER_CONSOLE_STRUCT *console);

/**
 * @brief Remove a previously added console (matched by func pointer).
 */
chcnav_return_code_t chcnav_logger_remove_console(const CHCNAV_LOGGER_CONSOLE_STRUCT *console);

/**
 * @brief Format and dispatch a log line to registered consoles.
 */
void chcnav_logger_output(CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E level, const char *module,
                          const char *fmt, ...);

#define CHCNAV_LOG_DEBUG(module, fmt, ...)                                                     \
    chcnav_logger_output(CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_DEBUG, #module, fmt, ##__VA_ARGS__)
#define CHCNAV_LOG_INFO(module, fmt, ...)                                                      \
    chcnav_logger_output(CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_INFO, #module, fmt, ##__VA_ARGS__)
#define CHCNAV_LOG_WARN(module, fmt, ...)                                                      \
    chcnav_logger_output(CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_WARN, #module, fmt, ##__VA_ARGS__)
#define CHCNAV_LOG_ERROR(module, fmt, ...)                                                     \
    chcnav_logger_output(CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_ERROR, #module, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* CHCNAV_LOGGER_H */
