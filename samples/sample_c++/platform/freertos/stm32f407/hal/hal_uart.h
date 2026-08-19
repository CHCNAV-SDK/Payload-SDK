/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file hal_uart.h
 * @brief This is the header file for "hal_uart.h",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_HAL_UART_H
#define CHCNAV_HAL_UART_H

#include "chcnav_platform.h"
#include "chcnav_error.h"
#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t hal_uart_init(CHCNAV_HAL_UART_NUM_E uart_num, uint32_t baud_rate, chcnav_uart_handle_t *uart_handle);
chcnav_return_code_t hal_uart_deinit(chcnav_uart_handle_t uart_handle);
chcnav_return_code_t hal_uart_write_data(chcnav_uart_handle_t uart_handle, const uint8_t *buffer, uint32_t len, uint32_t *real_len);
chcnav_return_code_t hal_uart_read_data(chcnav_uart_handle_t uart_handle, uint8_t *buffer, uint32_t len, uint32_t *real_len);
chcnav_return_code_t hal_uart_read_data_timeout(chcnav_uart_handle_t uart_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len,uint64_t timeout);
chcnav_return_code_t hal_uart_get_status(CHCNAV_HAL_UART_NUM_E uart_num, CHCNAV_UART_STATUS_STRUCT *status);

#ifdef __cplusplus
}
#endif
#endif
