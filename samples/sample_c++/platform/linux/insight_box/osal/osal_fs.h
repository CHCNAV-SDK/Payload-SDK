/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal_fs.h
 * @brief This is the header file for "osal_fs.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_OSAL_FS_H
#define CHCNAV_OSAL_FS_H

#include "chcnav_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t osal_file_open(const char *file_name,
                                    const char *file_mode,
                                    chcnav_file_handle_t *file_obj);

chcnav_return_code_t osal_file_close(chcnav_file_handle_t file_obj);

chcnav_return_code_t osal_file_write(chcnav_file_handle_t file_obj,
                                     const uint8_t *buffer, uint32_t len,
                                     uint32_t *real_len);

chcnav_return_code_t osal_file_read(chcnav_file_handle_t file_obj,
                                    uint8_t *buffer, uint32_t len,
                                    uint32_t *real_len);

chcnav_return_code_t osal_file_seek(chcnav_file_handle_t file_obj,
                                    uint32_t offset);

chcnav_return_code_t osal_file_sync(chcnav_file_handle_t file_obj);

chcnav_return_code_t osal_dir_open(const char *file_path,
                                   chcnav_dir_handle_t *dir_obj);

chcnav_return_code_t osal_dir_close(chcnav_dir_handle_t dir_obj);

chcnav_return_code_t osal_dir_read(chcnav_dir_handle_t dir_obj,
                                   CHCNAV_FILE_INFO_STRUCT *file_info);

chcnav_return_code_t osal_dir_create(const char *file_path);

chcnav_return_code_t osal_file_unlink(const char *file_path);

chcnav_return_code_t osal_file_rename(const char *oldfile_path,
                                      const char *newfile_path);

chcnav_return_code_t osal_file_stat(const char *file_path,
                                    CHCNAV_FILE_INFO_STRUCT *file_info);

#ifdef __cplusplus
}
#endif

#endif
