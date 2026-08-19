#ifndef TEST_GIMBAL_H
#define TEST_GIMBAL_H

#include "chcnav_error.h"
#include "chcnav_gimbal.h"
#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

chcnav_return_code_t chcnav_test_gimbal_start();
void chcnav_test_gimbal_stop();
bool chcnav_gimbal_is_inited();

#ifdef __cplusplus
}
#endif

#endif