/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_hlog.h
 * @brief declare for chcnav psdk logging interface
 ********************************************************************************/

#ifndef _CHCNAV_HLOG_H_
#define _CHCNAV_HLOG_H_

#include <sys/time.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// supported logging level
typedef enum {
  HLOG_VERBOSE = 0,
  HLOG_INFO = 1,
  HLOG_WARN = 2,
  HLOG_ERROR = 3,
  HLOG_FATAL = 4,
  HLOG_NUM_LEVEL // always be the last one for counting purpose
} CHCNAV_HLOG_LEVEL_E;

#define PATH_SEPARATOR '/'

#define __FILE_NAME__                                                          \
  (strrchr(__FILE__, PATH_SEPARATOR) ? strrchr(__FILE__, PATH_SEPARATOR) + 1   \
                                     : __FILE__)

#define CHCNAV_HLOG(module, level, format, ...)                                \
  do {                                                                         \
    if (chcnav_hlog_should_log_on_module_level(#module, HLOG_##level)) {       \
      chcnav_hlog_write_log(#module, HLOG_##level, __FILE_NAME__, __LINE__,    \
                            format, ##__VA_ARGS__);                            \
    }                                                                          \
  } while (0)

#define CHCNAV_HLOG_INFO(module, format, ...) CHCNAV_HLOG(module,INFO,format,##__VA_ARGS__)
#define CHCNAV_HLOG_ERROR(module, format, ...) CHCNAV_HLOG(module,ERROR,format,##__VA_ARGS__)
#define CHCNAV_HLOG_WARN(module, format, ...)  CHCNAV_HLOG(module,WARN,format,##__VA_ARGS__)

#define IS_VALID_CHCNAV_HLOG_LEVEL(level)                                      \
  ((level >= HLOG_VERBOSE) && (level < HLOG_NUM_LEVEL))

const char *chcnav_hlog_log_level_enum_to_string(CHCNAV_HLOG_LEVEL_E level);

// Convert logging level string to integer value, -1 means invalid input
CHCNAV_HLOG_LEVEL_E chcnav_hlog_log_level_string_to_enum(const char *str);

int chcnav_hlog_init(const char *app_name, const char *config_file = NULL);

int chcnav_hlog_flush();

int chcnav_hlog_sync_to_disk();

void chcnav_hlog_dump_hlog_settings();

bool chcnav_hlog_should_log_on_module_level(const char *module,
                                            CHCNAV_HLOG_LEVEL_E level);

int chcnav_hlog_write_log(const char *module, CHCNAV_HLOG_LEVEL_E level,
                          const char *filename, int line, const char *format,
                          ...);

#ifdef __cplusplus
}
#endif

#endif
