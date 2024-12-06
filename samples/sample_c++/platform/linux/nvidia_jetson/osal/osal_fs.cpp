/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file osal_fs.cpp
 * @brief This is the header file for "osal_fs.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#include "osal_fs.h"
#include "chcnav_error.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

chcnav_return_code_t osal_file_open(const char *file_name,
                                    const char *file_mode,
                                    chcnav_file_handle_t *file_obj) {
  if (file_name == nullptr || file_mode == nullptr || file_obj == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  *file_obj = fopen(file_name, file_mode);
  if (*file_obj == nullptr) {
    free(*file_obj);
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_close(chcnav_file_handle_t file_obj) {
  int32_t ret;

  if (file_obj == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = fclose((FILE *)file_obj);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_write(chcnav_file_handle_t file_obj,
                                     const uint8_t *buffer, uint32_t len,
                                     uint32_t *real_len) {
  int32_t ret;

  if (file_obj == nullptr || buffer == nullptr || len == 0 ||
      real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = fwrite(buffer, 1, len, (FILE *)file_obj);
  if (ret >= 0) {
    *real_len = ret;
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_read(chcnav_file_handle_t file_obj,
                                    uint8_t *buffer, uint32_t len,
                                    uint32_t *real_len) {
  int32_t ret;

  if (file_obj == nullptr || buffer == nullptr || len == 0 ||
      real_len == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = fread(buffer, 1, len, (FILE *)file_obj);
  if (ret >= 0) {
    *real_len = ret;
  } else {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_seek(chcnav_file_handle_t file_obj,
                                    uint32_t offset) {
  int32_t ret;

  if (file_obj == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = fseek((FILE *)file_obj, offset, SEEK_SET);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_sync(chcnav_file_handle_t file_obj) {
  int32_t ret;

  if (file_obj == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = fflush((FILE *)file_obj);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_dir_open(const char *file_path,
                                   chcnav_dir_handle_t *dir_obj) {
  if (file_path == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  *dir_obj = opendir(file_path);
  if (*dir_obj == nullptr) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_dir_close(chcnav_dir_handle_t dir_obj) {
  int32_t ret;

  if (dir_obj == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = closedir((DIR *)dir_obj);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_dir_read(chcnav_dir_handle_t dir_obj,
                                   CHCNAV_FILE_INFO_STRUCT *file_info) {
  struct dirent *dirent;

  if (dir_obj == nullptr || file_info == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  dirent = readdir((DIR *)dir_obj);
  if (!dirent) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  if (dirent->d_type == DT_DIR) {
    file_info->is_dir = true;
  } else {
    file_info->is_dir = false;
  }
  strcpy(file_info->path, dirent->d_name);

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_dir_create(const char *file_path) {
  int32_t ret;

  if (file_path == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = mkdir(file_path, S_IRWXU);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_unlink(const char *file_path) {
  int32_t ret;

  if (file_path == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  if (file_path[strlen(file_path) - 1] == '/') {
    ret = rmdir(file_path);
    if (ret < 0) {
      return CHCNAV_RETURN_OK;
    }
  } else {
    ret = unlink(file_path);
    if (ret < 0) {
      return CHCNAV_RETURN_OK;
    }
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_rename(const char *oldfile_path,
                                      const char *newfile_path) {
  int32_t ret;

  if (oldfile_path == nullptr || newfile_path == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = rename(oldfile_path, newfile_path);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t osal_file_stat(const char *file_path,
                                    CHCNAV_FILE_INFO_STRUCT *file_info) {
  struct stat st;
  int32_t ret;
  struct tm *fileTm;

  if (file_path == nullptr || file_info == nullptr) {
    return CHCNAV_RETURN_ERR_PARAM;
  }

  ret = stat(file_path, &st);
  if (ret < 0) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  fileTm = localtime(&(st.st_ctime));
  if (fileTm == nullptr) {
    return CHCNAV_RETURN_ERR_SYSTEM;
  }

  file_info->size = st.st_size;

  file_info->create_time.year = fileTm->tm_year + 1900 - 1980;
  file_info->create_time.month = fileTm->tm_mon;
  file_info->create_time.day = fileTm->tm_mday;
  file_info->create_time.hour = fileTm->tm_hour;
  file_info->create_time.minute = fileTm->tm_min;
  file_info->create_time.second = fileTm->tm_sec;

  return CHCNAV_RETURN_OK;
}
