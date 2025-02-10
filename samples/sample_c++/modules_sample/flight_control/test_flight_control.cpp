#include "test_flight_control.h"
#include "chcnav_flight_controller.h"
#include <iostream>

chcnav_return_code_t chcnav_run_flight_control_sample(CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_E flight_control_sample_select) {
    chcnav_return_code_t ret = -1;
    ret = chcnav_flight_controller_init();
    if (ret != CHCNAV_RESULT_SUCCESS) {
        std::cout << "chcnav_payload_camera_init failed" << std::endl;
        return ret;
    }

    return CHCNAV_RESULT_SUCCESS;
}

void chcnav_test_flight_control_normal_task_sample() {
    chcnav_return_code_t ret = -1;
}

void chcnav_test_flight_control_pause_during_flight_route_sample() {
    chcnav_return_code_t ret = -1;
}

void chcnav_test_flight_control_sample(CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_E flight_control_sample_select) {
    switch (flight_control_sample_select) {
        case CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_NORMAL_TASK: {
            chcnav_test_flight_control_normal_task_sample();
            break;
        }
        case CHCNAV_TEST_FLIGHT_CONTROL_SAMPLE_SELECT_PAUSE_DURING_FLIGHT_ROUTE: {
            chcnav_test_flight_control_pause_during_flight_route_sample();
            break;
        }
        default: {
            break;
        }
    }
}
