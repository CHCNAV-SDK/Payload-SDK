/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file hal_network.h
 * @brief This is the header file for "hal_network.h",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_HAL_NETWORK_H
#define CHCNAV_HAL_NETWORK_H

#include "chcnav_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LINUX_NETWORK_DEV           "eth1"

#define USB_NET_ADAPTER_VID         (0x0312)
#define USB_NET_ADAPTER_PID         (0x2010)

#define LINUX_CMD_STR_MAX_SIZE      (128)

chcnav_return_code_t hal_network_init(const char *ip_addr, const char *net_mask, chcnav_network_handle_t *network_handle);
chcnav_return_code_t hal_network_deinit(chcnav_network_handle_t network_handle);
chcnav_return_code_t hal_network_get_device_info(CHCNAV_HAL_NETWORK_DEVICE_INFO_STRUCT *device_info);

#ifdef __cplusplus
}
#endif

#endif