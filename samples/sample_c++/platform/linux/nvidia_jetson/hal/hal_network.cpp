/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file hal_network.cpp
 * @brief This is the header file for "hal_network.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "hal_network.h"
#include "chcnav_error.h"

chcnav_return_code_t hal_network_init(const char *ip_addr, const char *net_mask, chcnav_network_handle_t *network_handle)
{
    int32_t ret;
    char cmd_str[LINUX_CMD_STR_MAX_SIZE] = {0};

    if (ip_addr == nullptr || net_mask == nullptr) {
        std::cerr << "Hal_network_init config param error" << std::endl;
        return CHCNAV_RETURN_ERR_PARAM;
    }

    memset(cmd_str, 0, sizeof(cmd_str));

    snprintf(cmd_str, sizeof(cmd_str), "ifconfig %s up", LINUX_NETWORK_DEV);
    ret = system(cmd_str);
    if (ret != CHCNAV_RETURN_OK) {
        std::cerr << "Hal_network_init can't open the network." << std::endl;
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    snprintf(cmd_str, sizeof(cmd_str), "ifconfig %s %s net_mask %s", LINUX_NETWORK_DEV, ip_addr, net_mask);
    ret = system(cmd_str);
    if (ret != CHCNAV_RETURN_OK) {
        std::cout << "Hal_network_init can't config the ip address of network." << std::endl;
        return CHCNAV_RETURN_ERR_SYSTEM;
    }

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_network_deinit(chcnav_network_handle_t network_handle)
{
    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t hal_network_get_device_info(CHCNAV_HAL_NETWORK_DEVICE_INFO_STRUCT *device_info)
{
    device_info->USB_NET_ADAPTER_STRUCT.vid = USB_NET_ADAPTER_VID;
    device_info->USB_NET_ADAPTER_STRUCT.pid = USB_NET_ADAPTER_PID;

    return CHCNAV_RETURN_OK;
}
