#include "test_gimbal.h"
#include <iostream>
#include <ctime>
#include <math.h>
bool is_test_gimbal_inited = false;

chcnav_return_code_t
get_gimbal_information(CHCNAV_GIMBAL_INFORMATION_STRUCT *gimbal_information) {
  gimbal_information->uid = 0;
  gimbal_information->time_boot_ms = 1234; // ToDo
  gimbal_information->firmware_version = 0x05020102;
  gimbal_information->hardware_version = 0x05010102;
  gimbal_information->roll_min = 0;
  gimbal_information->roll_max = 55;
  gimbal_information->pitch_min = 0;
  gimbal_information->pitch_max = 125;
  gimbal_information->yaw_min = -10;
  gimbal_information->yaw_max = 70;
  gimbal_information->cap_flags = 4;
  gimbal_information->custom_cap_flags = 3;
  snprintf((char *)gimbal_information->vendor_name,
           sizeof(gimbal_information->vendor_name), "CHCNAV");
  snprintf((char *)gimbal_information->model_name,
           sizeof(gimbal_information->model_name), "gimbal");
  snprintf((char *)gimbal_information->custom_name,
           sizeof(gimbal_information->custom_name), "G10");

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_gimbal_attitude_state(CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT *system_state) {
  std::srand(std::time(0));
  double random = (std::rand() / (double)RAND_MAX) * 2.0;
  system_state->time_boot_ms = 1234;
  system_state->q[0] = random;
  random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->q[1] = random;
  random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->q[2] = random;
  random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->q[3] = random;
  // random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->angular_velocity_x = NAN;
  // random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->angular_velocity_y = NAN;
  // random = (std::rand() / (double)RAND_MAX) * 50.0;
  system_state->angular_velocity_z = NAN;
  system_state->failure_flags = 0;
  system_state->delta_yaw = 0.3;
  system_state->delta_yaw_velocity = 0.5;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_gimbal_attitude(CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT *attitude) {
  attitude->q[0] = 0.1;
  attitude->q[1] = 0.2;
  attitude->q[2] = 0.3;
  attitude->q[3] = 0.4;
  attitude->angular_velocity_x = 2.3;
  attitude->angular_velocity_y = 2.4;
  attitude->angular_velocity_z = 2.5;
  attitude->flags = 2;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_gimbal_mode(CHCNAV_GIMBAL_MODE_E mode) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_gimbal_mode(CHCNAV_GIMBAL_MODE_E *mode) {
  *mode = CHCNAV_GIMBAL_MODE_FPV;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t reset_mode(CHCNAV_GIMBAL_RESET_MODE_E mode) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t reset_factory_settings(void) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t chcnav_test_gimbal_start() {
  chcnav_return_code_t ret = chcnav_gimbal_init();
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "gimbal init failed" << std::endl;
  }

  CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT common_handler{};
  common_handler.get_gimbal_information = get_gimbal_information;
  common_handler.get_gimbal_attitude_state = get_gimbal_attitude_state;
  common_handler.set_gimbal_attitude = set_gimbal_attitude;
  common_handler.set_gimbal_mode = set_gimbal_mode;
  common_handler.get_gimbal_mode = get_gimbal_mode;
  common_handler.reset_mode = reset_mode;
  common_handler.reset_factory_settings = reset_factory_settings;
  ret = chcnav_gimbal_register_common_handler(&common_handler);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "gimbal register common handler failed" << std::endl;
  }

  is_test_gimbal_inited = true;
  return CHCNAV_RETURN_OK;
}

bool chcnav_gimbal_is_inited() { return is_test_gimbal_inited; }