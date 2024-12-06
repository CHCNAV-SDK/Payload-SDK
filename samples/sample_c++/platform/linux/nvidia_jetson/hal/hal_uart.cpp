/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file hal_uart.cpp
 * @brief This is the header file for "hal_uart.cpp".
 ********************************************************************************/

#include "hal_uart.h"
#include "chcnav_error.h"

#define UART_DEV_NAME_STR_SIZE (64)
#define CHCNAV_SYSTEM_CMD_STR_MAX_SIZE (128)

typedef struct {
  int uart_fd;
} UART_HANDLE_STRUCT;

chcnav_return_code_t hal_uart_init(uint32_t baud_rate,
                                   chcnav_uart_handle_t *uart_handle) {

  struct flock lock;
  struct termios options;
  UART_HANDLE_STRUCT *uart_handle_struct;
  chcnav_return_code_t return_code = CHCNAV_RETURN_OK;
  char uart_name[UART_DEV_NAME_STR_SIZE];
  char system_cmd[CHCNAV_SYSTEM_CMD_STR_MAX_SIZE];

  uart_handle_struct = (UART_HANDLE_STRUCT *)malloc(sizeof(UART_HANDLE_STRUCT));
  if (uart_handle_struct == nullptr) {
    return CHCNAV_RETURN_ERR_ALLOC;
  }

  strcpy(uart_name, LINUX_UART_DEV);

  if (0 != access(uart_name, F_OK)) {
    goto free_handle;
  }

  uart_handle_struct->uart_fd = open(
      uart_name, (unsigned)O_RDWR | (unsigned)O_NOCTTY | (unsigned)O_NDELAY);
  if (uart_handle_struct->uart_fd == -1) {
    goto close_fp;
  }

  lock.l_type = F_WRLCK;
  lock.l_pid = getpid();
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;

  if (fcntl(uart_handle_struct->uart_fd, F_GETLK, &lock) < 0) {
    goto close_fd;
  }
  if (lock.l_type != F_UNLCK) {
    goto close_fd;
  }
  lock.l_type = F_WRLCK;
  lock.l_pid = getpid();
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  if (fcntl(uart_handle_struct->uart_fd, F_SETLKW, &lock) < 0) {
    goto close_fd;
  }

  if (tcgetattr(uart_handle_struct->uart_fd, &options) != 0) {
    goto close_fd;
  }

  switch (baud_rate) {
  case 115200:
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);
    break;
  case 230400:
    cfsetispeed(&options, B230400);
    cfsetospeed(&options, B230400);
    break;
  case 460800:
    cfsetispeed(&options, B460800);
    cfsetospeed(&options, B460800);
    break;
  case 921600:
    cfsetispeed(&options, B921600);
    cfsetospeed(&options, B921600);
    break;
  case 1000000:
    cfsetispeed(&options, B1000000);
    cfsetospeed(&options, B1000000);
    break;
  default:
    goto close_fd;
  }

  options.c_cflag |= (unsigned)CLOCAL;
  options.c_cflag |= (unsigned)CREAD;
  options.c_cflag &= ~(unsigned)CRTSCTS;
  options.c_cflag &= ~(unsigned)CSIZE;
  options.c_cflag |= (unsigned)CS8;
  options.c_cflag &= ~(unsigned)PARENB;
  options.c_iflag &= ~(unsigned)INPCK;
  options.c_cflag &= ~(unsigned)CSTOPB;
  options.c_oflag &= ~(unsigned)OPOST;
  options.c_lflag &=
      ~((unsigned)ICANON | (unsigned)ECHO | (unsigned)ECHOE | (unsigned)ISIG);
  options.c_iflag &= ~((unsigned)BRKINT | (unsigned)ICRNL | (unsigned)INPCK |
                       (unsigned)ISTRIP | (unsigned)IXON);
  options.c_cc[VTIME] = 0;
  options.c_cc[VMIN] = 0;

  tcflush(uart_handle_struct->uart_fd, TCIFLUSH);

  if (tcsetattr(uart_handle_struct->uart_fd, TCSANOW, &options) != 0) {
    goto close_fd;
  }

  *uart_handle = uart_handle_struct;

  return return_code;

free_handle:
  free(uart_handle_struct);
close_fd:
  close(uart_handle_struct->uart_fd);

close_fp:
  return CHCNAV_RETURN_ERR_SYSTEM;
}

chcnav_return_code_t hal_uart_deinit(chcnav_uart_handle_t uart_handle) {
  int32_t ret;
  UART_HANDLE_STRUCT *uart_handle_struct = (UART_HANDLE_STRUCT *)uart_handle;

  if (uart_handle == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = close(uart_handle_struct->uart_fd);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  free(uart_handle_struct);

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_write_data(chcnav_uart_handle_t uart_handle,
                                         const uint8_t *buffer, uint32_t len,
                                         uint32_t *real_len) {
  int32_t ret;
  UART_HANDLE_STRUCT *uart_handle_struct = (UART_HANDLE_STRUCT *)uart_handle;

  if ((uart_handle == nullptr) || (buffer == nullptr) || (len == 0) ||
      (real_len == nullptr)) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = write(uart_handle_struct->uart_fd, buffer, len);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  *real_len = ret;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_read_data(chcnav_uart_handle_t uart_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len) {
  if ((uart_handle == nullptr) || (buffer == nullptr) || (len == 0) ||
      (real_len == nullptr)) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  int32_t ret;
  UART_HANDLE_STRUCT *uart_handle_struct = (UART_HANDLE_STRUCT *)uart_handle;

  ret = read(uart_handle_struct->uart_fd, buffer, len);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  *real_len = ret;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
hal_uart_read_data_timeout(chcnav_uart_handle_t uart_handle, uint8_t *buffer,
                           uint32_t len, uint32_t *real_len, uint64_t timeout) {
  if ((uart_handle == nullptr) || (buffer == nullptr) || (len == 0) ||
      (real_len == nullptr)) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  fd_set rfds;
  struct timeval tv;
  int ret_val;
  uint32_t ret = 0;
  UART_HANDLE_STRUCT *uart_handle_struct = (UART_HANDLE_STRUCT *)uart_handle;

  FD_ZERO(&rfds);
  FD_SET(uart_handle_struct->uart_fd, &rfds);

  tv.tv_sec = timeout / 1000000;
  tv.tv_usec = timeout % 1000000;
  ret_val = select(uart_handle_struct->uart_fd + 1, &rfds, NULL, NULL, &tv);
  if (ret_val <= 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  if (!FD_ISSET(uart_handle_struct->uart_fd, &rfds)) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  if ((ret = read(uart_handle_struct->uart_fd, buffer, len)) < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }
  *real_len = ret;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_uart_get_status(CHCNAV_UART_STATUS_STRUCT *status) {
  status->is_connect = true;
  return CHCNAV_RETURN_OK;
}
