/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_platform.h
 * @brief This is the header file for "chcnav_platform.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_PLATFORM_H
#define CHCNAV_PLATFORM_H
#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Platform handle of uart operation.
 */
typedef void *chcnav_uart_handle_t;

/**
 * @brief Platform handle of usb bulk operation.
 */
typedef void *chcnav_usb_bulk_handle_t;

/**
 * @brief Platform handle of network operation.
 */
typedef void *chcnav_network_handle_t;

/**
 * @brief Platform handle of thread task operation.
 */
typedef void *chcnav_task_handle_t;
/**
 * @brief Platform handle of mutex operation.
 */
typedef void *chcnav_mutex_handle_t;

/**
 * @brief Platform handle of semaphore operation.
 */
typedef void *chcnav_semaphore_handle_t;

/**
 * @brief Platform handle of file operation.
 */
typedef void *chcnav_file_handle_t;
/**
 * @brief Platform handle of directory operation.
 */
typedef void *chcnav_dir_handle_t;

/**
 * @brief Platform handle of socket operation.
 */
typedef void *chcnav_socket_handle_t;

typedef enum {
  /*used by camera manager */
  CHCNAV_HAL_UART_NUM_0 = 0,
  /*used by payload camera */
  CHCNAV_HAL_UART_NUM_1 = 1,
} CHCNAV_HAL_UART_NUM_E;

typedef enum {
  CHCNAV_HAL_USB_BULK_NUM_0 = 0,
  CHCNAV_HAL_USB_BULK_NUM_1,
  CHCNAV_HAL_USB_BULK_NUM_MAX
} CHCNAV_HAL_USB_BULK_NUM_E;

typedef enum {
  CHCNAV_SOCKET_MODE_UDP = 0,
  CHCNAV_SOCKET_MODE_TCP
} CHCNAV_SOCKET_MODE_E;

typedef struct {
  bool is_connect;
} CHCNAV_UART_STATUS_STRUCT;

typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
} CHCNAV_TIME_STRUCT;

typedef struct {
  uint32_t size;
  CHCNAV_TIME_STRUCT create_time;
  CHCNAV_TIME_STRUCT modify_time;
  char path[CHCNAV_FILE_PATH_SIZE_MAX];
  bool is_dir;
} CHCNAV_FILE_INFO_STRUCT;

typedef struct {
  chcnav_return_code_t (*uart_init)(CHCNAV_HAL_UART_NUM_E uart_num, uint32_t baud_rate,
                                    chcnav_uart_handle_t *uart_handle);

  chcnav_return_code_t (*uart_deinit)(chcnav_uart_handle_t uart_handle);

  chcnav_return_code_t (*uart_write_data)(chcnav_uart_handle_t uart_handle,
                                          const uint8_t *buffer, uint32_t len,
                                          uint32_t *real_len);

  chcnav_return_code_t (*uart_read_data)(chcnav_uart_handle_t uart_handle,
                                         uint8_t *buffer, uint32_t len,
                                         uint32_t *real_len);
  chcnav_return_code_t (*uart_read_data_timeout)(chcnav_uart_handle_t uart_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len,uint64_t timeout);
  chcnav_return_code_t (*uart_get_status)(CHCNAV_HAL_UART_NUM_E uart_num, CHCNAV_UART_STATUS_STRUCT *status);
} CHCNAV_HAL_UART_HANDLER_STRUCT;

typedef struct {
  uint16_t interface_num;
  uint16_t end_point_in;
  uint16_t end_point_out;
} CHCNAV_HAL_USB_BULK_CHANNEL_INFO_STRUCT;

typedef struct {
  bool is_usb_host;
  // attention: if 'is_usb_host' is false, the following parameters is not
  // valid.
  uint16_t pid;
  uint16_t vid;
  CHCNAV_HAL_USB_BULK_CHANNEL_INFO_STRUCT channel_info;
} CHCNAV_HAL_USB_BULK_INFO_STRUCT;

typedef struct {
  uint16_t pid;
  uint16_t vid;
  CHCNAV_HAL_USB_BULK_CHANNEL_INFO_STRUCT
  channel_info[CHCNAV_HAL_USB_BULK_NUM_MAX];
} CHCNAV_HAL_USB_BULK_DEVICE_INFO_STRUCT;

typedef struct {
  struct {
    uint16_t vid;
    uint16_t pid;
  } USB_NET_ADAPTER_STRUCT;
} CHCNAV_HAL_NETWORK_DEVICE_INFO_STRUCT;

typedef struct {
  chcnav_return_code_t (*usb_bulk_init)(
      CHCNAV_HAL_USB_BULK_INFO_STRUCT usb_bulk_info,
      chcnav_usb_bulk_handle_t *usb_bulk_handle);

  chcnav_return_code_t (*usb_bulk_deinit)(
      chcnav_usb_bulk_handle_t usb_bulk_handle);

  chcnav_return_code_t (*usb_bulk_write_data)(
      chcnav_usb_bulk_handle_t usb_bulk_handle, const uint8_t *buffer,
      uint32_t len, uint32_t *real_len);

  chcnav_return_code_t (*usb_bulk_read_data)(
      chcnav_usb_bulk_handle_t usb_bulk_handle, uint8_t *buffer, uint32_t len,
      uint32_t *real_len);

  chcnav_return_code_t (*usb_bulk_get_device_info)(
      CHCNAV_HAL_USB_BULK_DEVICE_INFO_STRUCT *device_info);
} CHCNAV_HAL_USB_BULK_HANDLER_STRUCT;

typedef struct {
  chcnav_return_code_t (*network_init)(const char *ip_addr,
                                       const char *net_mask,
                                       chcnav_network_handle_t *network_handle);

  chcnav_return_code_t (*network_deinit)(
      chcnav_network_handle_t network_handle);

  chcnav_return_code_t (*network_get_device_info)(
      CHCNAV_HAL_NETWORK_DEVICE_INFO_STRUCT *device_info);
} CHCNAV_HAL_NETWORK_HANDLER_STRUCT;

typedef struct {
  chcnav_return_code_t (*task_create)(const char *name,
                                      void *(*task_func)(void *),
                                      uint32_t stack_size, void *arg,
                                      chcnav_task_handle_t *task);

  chcnav_return_code_t (*task_destroy)(chcnav_task_handle_t task);

  chcnav_return_code_t (*task_sleep_ms)(uint32_t time_ms);

  chcnav_return_code_t (*mutex_create)(chcnav_mutex_handle_t *mutex);

  chcnav_return_code_t (*mutex_destroy)(chcnav_mutex_handle_t mutex);

  chcnav_return_code_t (*mutex_lock)(chcnav_mutex_handle_t mutex);

  chcnav_return_code_t (*mutex_unlock)(chcnav_mutex_handle_t mutex);

  chcnav_return_code_t (*semaphore_create)(
      uint32_t init_value, chcnav_semaphore_handle_t *semaphore);

  chcnav_return_code_t (*semaphore_destroy)(
      chcnav_semaphore_handle_t semaphore);

  chcnav_return_code_t (*semaphore_wait)(chcnav_semaphore_handle_t semaphore);

  chcnav_return_code_t (*semaphore_timed_wait)(
      chcnav_semaphore_handle_t semaphore, uint32_t wait_time_ms);

  chcnav_return_code_t (*semaphore_post)(chcnav_semaphore_handle_t semaphore);

  chcnav_return_code_t (*get_time_ms)(uint32_t *ms);

  chcnav_return_code_t (*get_time_us)(uint64_t *us);

  void *(*malloc)(uint32_t size);

  void (*free)(void *ptr);
} CHCNAV_OSAL_HANDLER_STRUCT;

typedef struct {
  chcnav_return_code_t (*file_open)(const char *file_name,
                                    const char *file_mode,
                                    chcnav_file_handle_t *file_obj);

  chcnav_return_code_t (*file_close)(chcnav_file_handle_t file_obj);

  chcnav_return_code_t (*file_write)(chcnav_file_handle_t file_obj,
                                     const uint8_t *buffer, uint32_t len,
                                     uint32_t *real_len);

  chcnav_return_code_t (*file_read)(chcnav_file_handle_t file_obj,
                                    uint8_t *buffer, uint32_t len,
                                    uint32_t *real_len);

  chcnav_return_code_t (*file_seek)(chcnav_file_handle_t file_obj,
                                    uint32_t offset);

  chcnav_return_code_t (*file_sync)(chcnav_file_handle_t file_obj);

  chcnav_return_code_t (*dir_open)(const char *file_path,
                                   chcnav_dir_handle_t *dir_obj);

  chcnav_return_code_t (*dir_close)(chcnav_dir_handle_t dir_obj);

  chcnav_return_code_t (*dir_read)(chcnav_dir_handle_t dir_obj,
                                   CHCNAV_FILE_INFO_STRUCT *file_info);

  chcnav_return_code_t (*dir_create)(const char *file_path);

  chcnav_return_code_t (*file_unlink)(const char *file_path);

  chcnav_return_code_t (*file_rename)(const char *old_file_path,
                                      const char *new_file_path);

  chcnav_return_code_t (*file_stat)(const char *file_path,
                                    CHCNAV_FILE_INFO_STRUCT *file_info);
} CHCNAV_FILE_SYSTEM_HANDLER_STRUCT;

typedef struct {
  chcnav_return_code_t (*socket_create)(CHCNAV_SOCKET_MODE_E mode,
                                        chcnav_socket_handle_t *socket_handle);

  chcnav_return_code_t (*socket_close)(chcnav_socket_handle_t socket_handle);

  chcnav_return_code_t (*socket_bind)(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port);

  chcnav_return_code_t (*udp_send_data)(chcnav_socket_handle_t socket_handle,
                                        const char *ip_addr, uint32_t port,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

  chcnav_return_code_t (*udp_recv_data)(chcnav_socket_handle_t socket_handle,
                                        char *ip_addr, uint32_t *port,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

  chcnav_return_code_t (*tcp_listen)(chcnav_socket_handle_t socket_handle);

  chcnav_return_code_t (*tcp_accept)(chcnav_socket_handle_t socket_handle,
                                     char *ip_addr, uint32_t *port,
                                     chcnav_socket_handle_t *out_socket_handle);

  chcnav_return_code_t (*tcp_connect)(chcnav_socket_handle_t socket_handle,
                                      const char *ip_addr, uint32_t port);

  chcnav_return_code_t (*tcp_send_data)(chcnav_socket_handle_t socket_handle,
                                        const uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);

  chcnav_return_code_t (*tcp_recv_data)(chcnav_socket_handle_t socket_handle,
                                        uint8_t *buffer, uint32_t len,
                                        uint32_t *real_len);
} CHCNAV_SOCKET_HANDLER_STRUCT;

/**
 * @brief Register the handler for hal uart interfaces by your platform.
 * @param hal_uart_handler: pointer to the handler for hal uart interfaces by
 * your platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_hal_uart_handler(
    const CHCNAV_HAL_UART_HANDLER_STRUCT *hal_uart_handler);

/**
 * @brief Register the handler for usb bulk interfaces by your platform.
 * @param hal_usb_bulk_handler: pointer to the handler for usb bulk interfaces
 * by your platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_hal_usb_bulk_handler(
    const CHCNAV_HAL_USB_BULK_HANDLER_STRUCT *hal_usb_bulk_handler);

/**
 * @brief Register the handler for hal network interfaces by your platform.
 * @attention The interface needs to be called at the beginning of the
 * application for registration, otherwise, the subsequent functions will not
 * work properly.
 * @param hal_network_handler: pointer to the handler for network handler
 * interfaces by your platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_hal_network_handler(
    const CHCNAV_HAL_NETWORK_HANDLER_STRUCT *hal_network_handler);

/**
 * @brief Register the handler for osal interfaces by your platform.
 * @param osal_handler: pointer to the handler for osal interfaces by your
 * platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_osal_handler(
    const CHCNAV_OSAL_HANDLER_STRUCT *osal_handler);

/**
 * @brief Register the handler for file-system interfaces by your platform.
 * @param file_system_handler: pointer to the handler for file-system interfaces
 * by your platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_file_system_handler(
    const CHCNAV_FILE_SYSTEM_HANDLER_STRUCT *file_system_handler);

/**
 * @brief Register the handler for socket interfaces by your platform.
 * @param socket_handler: pointer to the handler for socket interfaces by your
 * platform.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_platform_reg_socket_handler(
    const CHCNAV_SOCKET_HANDLER_STRUCT *socket_handler);

/**
 * @brief Get the handler of osal interfaces.
 * @return Pointer to osal handler.
 */
CHCNAV_OSAL_HANDLER_STRUCT *chcnav_platform_get_osal_handler(void);

/**
 * @brief Get the handler of usb bulk interfaces.
 * @return Pointer to usb bulk handler.
 */
CHCNAV_HAL_USB_BULK_HANDLER_STRUCT *
chcnav_platform_get_hal_usb_bulk_handler(void);

/**
 * @brief Get the handler of network interfaces.
 * @return Pointer to network handler.
 */
CHCNAV_HAL_NETWORK_HANDLER_STRUCT *
chcnav_platform_get_hal_network_handler(void);

/**
 * @brief Get the handler of file-system interfaces.
 * @return Pointer to file-system handler.
 */
CHCNAV_FILE_SYSTEM_HANDLER_STRUCT *
chcnav_platform_get_file_system_handler(void);

/**
 * @brief Get the handler of socket interfaces.
 * @return Pointer to socket handler.
 */
CHCNAV_SOCKET_HANDLER_STRUCT *chcnav_platform_get_socket_handler(void);

#ifdef __cplusplus
}
#endif

#endif