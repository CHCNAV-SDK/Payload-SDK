#ifndef TEST_FLIGHT_CONTROL_H
#define TEST_FLIGHT_CONTROL_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_NORMAL_TASK,
    CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_PAUSE_DURING_FLIGHT_ROUTE,
} CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_E;

/**
 * @brief Run flight control sample.
 * @return chcnav_return_code_t.
 */
chcnav_return_code_t chcnav_run_flight_control_sample(CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_E flight_control_sample_select);


#ifdef __cplusplus
}
#endif

#endif