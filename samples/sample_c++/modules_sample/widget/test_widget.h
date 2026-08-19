#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H

#include "chcnav_error.h"
#include "chcnav_widget.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t chcnav_test_widget_start(void);
void chcnav_test_widget_stop(void);
chcnav_return_code_t chcnav_test_widget_set_config_file_path(const char *path);

#ifdef __cplusplus
}
#endif
#endif
