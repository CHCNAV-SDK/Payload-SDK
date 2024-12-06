/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal_socket.cpp
 ********************************************************************************/

#include "osal_socket.h"
#include "chcnav_error.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define SOCKET_RECV_BUF_MAX_SIZE (1024 * 1000 * 10)

typedef struct {
  int socket_fd;
} SOCKET_HANDLE_STRUCT;

chcnav_return_code_t osal_socket_create(CHCNAV_SOCKET_MODE_E mode,
                                        chcnav_socket_handle_t *socket_handle) {
  SOCKET_HANDLE_STRUCT *socket_handle_struct;
  socklen_t socket_len = sizeof(int);
  int recv_buffer_size = SOCKET_RECV_BUF_MAX_SIZE;
  int opt = 1;

  if (socket_handle == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)malloc(sizeof(SOCKET_HANDLE_STRUCT));
  if (socket_handle_struct == nullptr) {
    return CHCNAV_RETURN_ERR_ALLOC;
  }

  if (mode == CHCNAV_SOCKET_MODE_UDP) {
    socket_handle_struct->socket_fd = socket(PF_INET, SOCK_DGRAM, 0);

    if (setsockopt(socket_handle_struct->socket_fd, SOL_SOCKET, SO_REUSEADDR,
                   &opt, socket_len) < 0) {
      goto err;
    }

    if (setsockopt(socket_handle_struct->socket_fd, SOL_SOCKET, SO_RCVBUF,
                   &recv_buffer_size, socket_len) < 0) {
      goto err;
    }
  } else if (mode == CHCNAV_SOCKET_MODE_TCP) {
    socket_handle_struct->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
  } else {
    goto err;
  }

  *socket_handle = socket_handle_struct;

  return CHCNAV_RETURN_OK;

err:
  close(socket_handle_struct->socket_fd);
  free(socket_handle_struct);

  return CHCNAV_RETURN_ERR_SYSTEM;
}

chcnav_return_code_t osal_socket_close(chcnav_socket_handle_t socket_handle) {
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle_struct->socket_fd <= 0) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret = close(socket_handle_struct->socket_fd);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  free(socket_handle);

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_socket_bind(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port) {
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;
  struct sockaddr_in addr;

  if (socket_handle == nullptr || ip_addr == nullptr || port == 0) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip_addr);

  int32_t ret = bind(socket_handle_struct->socket_fd, (struct sockaddr *)&addr,
                     sizeof(struct sockaddr_in));
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_udp_send_data(chcnav_socket_handle_t socket_handle,
                                        const char *ip_addr, uint32_t port,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len) {
  struct sockaddr_in addr;
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle == nullptr || ip_addr == nullptr || port == 0 ||
      buffer == nullptr || len == 0 || real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip_addr);

  int32_t ret = sendto(socket_handle_struct->socket_fd, buffer, len, 0,
                       (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  if (ret >= 0) {
    *real_len = ret;
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_udp_recv_data(chcnav_socket_handle_t socket_handle,
                                        char *ip_addr, uint32_t *port,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len) {
  struct sockaddr_in addr;
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;
  uint32_t addr_len = 0;

  if (socket_handle == nullptr || ip_addr == nullptr || port == 0 ||
      buffer == nullptr || len == 0 || real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret = recvfrom(socket_handle_struct->socket_fd, buffer, len, 0,
                         (struct sockaddr *)&addr, &addr_len);
  if (ret >= 0) {
    *real_len = ret;
    strcpy(ip_addr, inet_ntoa(addr.sin_addr));
    *port = ntohs(addr.sin_port);
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_tcp_listen(chcnav_socket_handle_t socket_handle) {
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret = listen(socket_handle_struct->socket_fd, 5);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_tcp_accept(chcnav_socket_handle_t socket_handle,
                                     char *ip_addr, uint32_t *port,
                                     chcnav_socket_handle_t *out_socket_handle)

{
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;
  SOCKET_HANDLE_STRUCT *socket_handle_struct_out;
  struct sockaddr_in addr;
  uint32_t addr_len = 0;

  if (socket_handle == nullptr || ip_addr == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  socket_handle_struct_out =
      (SOCKET_HANDLE_STRUCT *)malloc(sizeof(SOCKET_HANDLE_STRUCT));
  if (socket_handle_struct_out == nullptr) {
    return CHCNAV_RETURN_ERR_ALLOC;
  }

  socket_handle_struct_out->socket_fd = accept(
      socket_handle_struct->socket_fd, (struct sockaddr *)&addr, &addr_len);
  if (socket_handle_struct_out->socket_fd < 0) {
    free(socket_handle_struct_out);
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  *port = ntohs(addr.sin_port);
  *out_socket_handle = socket_handle_struct_out;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_tcp_connect(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port) {
  struct sockaddr_in addr;
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle == nullptr || ip_addr == nullptr || port == 0) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  bzero(&addr, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip_addr);

  int32_t ret = connect(socket_handle_struct->socket_fd,
                        (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t osal_tcp_send_data(chcnav_socket_handle_t socket_handle,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len)

{
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle == nullptr || buffer == nullptr || len == 0 ||
      real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret = send(socket_handle_struct->socket_fd, buffer, len, 0);
  if (ret >= 0) {
    *real_len = ret;
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_tcp_recv_data(chcnav_socket_handle_t socket_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len)

{
  SOCKET_HANDLE_STRUCT *socket_handle_struct =
      (SOCKET_HANDLE_STRUCT *)socket_handle;

  if (socket_handle == nullptr || buffer == nullptr || len == 0 ||
      real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret = recv(socket_handle_struct->socket_fd, buffer, len, 0);
  if (ret >= 0) {
    *real_len = ret;
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}