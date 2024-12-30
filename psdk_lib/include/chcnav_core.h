/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_core.h
 * @brief This is the header file for "chcnav_core.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_CORE_H
#define CHCNAV_CORE_H

#include "chcnav_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief Initialize the Payload SDK core
 * @note First call this interface to initialize the PSDK
 * @return Execution result.
 */
chcnav_return_code_t chcnav_core_init();

/**
 * @brief Start the Payload SDK core
 * @return Execution result.
 */
chcnav_return_code_t chcnav_core_start();

/**
 * @brief DeInitialize the Payload SDK core.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_core_deinit(void);
#ifdef __cplusplus
}
#endif

#endif // CHCNAV_CORE_H
