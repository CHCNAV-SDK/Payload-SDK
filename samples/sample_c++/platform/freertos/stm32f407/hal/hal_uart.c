/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file hal_uart.c
 * @brief This is the header file for "hal_uart.c".
 ********************************************************************************/
#include "hal_uart.h"
#include "stm32f4xx_hal.h"

#include "../Drivers/BSP/usart.h"

typedef struct {
	CHCNAV_HAL_UART_NUM_E uart_num;
} UartHandleStruct;

chcnav_return_code_t hal_uart_init(CHCNAV_HAL_UART_NUM_E uart_num, uint32_t baud_rate,
                                   chcnav_uart_handle_t *uart_handle)
{
	UartHandleStruct *uart;
	//uart = pvPortMalloc(sizeof(UartHandleStruct));
	uart = malloc(sizeof(UartHandleStruct));
    if (uart == NULL)
    {
        return CHCNAV_RETURN_ERR_ALLOC;
    }

    if (uart_num == CHCNAV_HAL_UART_NUM_1)
    {
    	MX_USART1_UART_Init(baud_rate);
    	uart->uart_num = uart_num;
    }
    else
    {
    	return CHCNAV_RETURN_ERR_PARAM;
    }

    *uart_handle = uart;

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_deinit(chcnav_uart_handle_t uart_handle)
{
	UartHandleStruct *uart = (UartHandleStruct *) uart_handle;
	if (uart == NULL)
		return CHCNAV_RETURN_ERR_PARAM;

    //vPortFree(uart);
	free(uart);
    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_write_data(chcnav_uart_handle_t uart_handle,
                                         const uint8_t *buffer, uint32_t len,
                                         uint32_t *real_len)
{
	const UartHandleStruct *uart = (UartHandleStruct *) uart_handle;
	if (uart == NULL || buffer == NULL)
		return CHCNAV_RETURN_ERR_PARAM;

	if (uart->uart_num == CHCNAV_HAL_UART_NUM_1)
	{
		MX_USART1_UART_Send(buffer, len, 0xFFFF);
	}

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_read_data(chcnav_uart_handle_t uart_handle, uint8_t *buffer, uint32_t len, uint32_t *real_len)
{
	const UartHandleStruct *uart = (UartHandleStruct *) uart_handle;
	if (uart_handle == NULL || buffer == NULL)
		return CHCNAV_RETURN_ERR_PARAM;

    if (uart->uart_num == CHCNAV_HAL_UART_NUM_1)
    {
    	*real_len = MX_USART1_UART_Receive(buffer, len);
    }
    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_read_data_timeout(chcnav_uart_handle_t uart_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len,uint64_t timeout)
{
	if (uart_handle == NULL || buffer == NULL)
		return CHCNAV_RETURN_ERR_PARAM;

	const UartHandleStruct *uart = (UartHandleStruct *) uart_handle;
	uint64_t time_count = 0;
	while(time_count <= timeout)
	{
		if (uart->uart_num == CHCNAV_HAL_UART_NUM_1)
		{
			*real_len = MX_USART1_UART_Receive(buffer, len);
		}
		if (*real_len > 0)
		{
			return CHCNAV_RETURN_OK;
		}
		time_count++;
		osal_task_sleep_ms(1);
	}

	return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_get_status(CHCNAV_HAL_UART_NUM_E uart_num, CHCNAV_UART_STATUS_STRUCT *status)
{
	if (uart_num == CHCNAV_HAL_UART_NUM_1)
		status->is_connect = true;
	else if (uart_num == CHCNAV_HAL_UART_NUM_1)
		status->is_connect = false;

	return CHCNAV_RETURN_OK;
}
