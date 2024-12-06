/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal_socket.h
 * @brief This is the header file for "osal_socket.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_OSAL_SOCKET_H
#define CHCNAV_OSAL_SOCKET_H

/* Includes ------------------------------------------------------------------*/
#include "chcnav_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t osal_socket_create(CHCNAV_SOCKET_MODE_E mode,
                                        chcnav_socket_handle_t *socket_handle);

chcnav_return_code_t osal_socket_close(chcnav_socket_handle_t socket_handle);

chcnav_return_code_t osal_socket_bind(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port);

chcnav_return_code_t osal_udp_send_data(chcnav_socket_handle_t socket_handle,
                                        const char *ip_addr, uint32_t port,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

chcnav_return_code_t osal_udp_recv_data(chcnav_socket_handle_t socket_handle,
                                        char *ip_addr, uint32_t *port,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

chcnav_return_code_t osal_tcp_listen(chcnav_socket_handle_t socket_handle);

chcnav_return_code_t osal_tcp_accept(chcnav_socket_handle_t socket_handle,
                                     char *ip_addr, uint32_t *port,
                                     chcnav_socket_handle_t *out_socket_handle);

chcnav_return_code_t osal_tcp_connect(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port);

chcnav_return_code_t osal_tcp_send_data(chcnav_socket_handle_t socket_handle,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

chcnav_return_code_t osal_tcp_recv_data(chcnav_socket_handle_t socket_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

#ifdef __cplusplus
}
#endif

#endif