#include "test_gimbal.h"
#include <iostream>
#include <ctime>
#include <math.h>

static const double PI = 3.14159265358979323846;

bool is_test_gimbal_inited = false;

void quaternion_to_euler_anger(float& pitch, float& yaw, float& roll, const float* q)
{
    roll = (float)asinf(-2 * q[1] * q[3] + 2 * q[0] * q[2]) * 180 / PI;

    pitch = (float)atan2f(2 * q[1] * q[2] + 2 * q[0] * q[3], -2 * q[2] * q[2] - 2 * q[3] * q[3] + 1) * 180 / PI;

    yaw = (float)atan2f(2 * q[2] * q[3] + 2 * q[0] * q[1], -2 * q[1] * q[1] - 2 * q[2] * q[2] + 1) * 180 / PI;
}

/*
* pitch/yaw/roll: Input gimbal attitude angle. unit:deg
*/
void euler_anger_to_quaternion(float pitch, float yaw, float roll, float* q)
{
    float rad_roll = roll * PI / 180;
    float rad_pitch = pitch * PI / 180;
    float rad_yaw = yaw * PI / 180;

    float c1 = cos(rad_roll / 2);
    float s1 = sin(rad_roll / 2);
    float c2 = cos(rad_pitch / 2);
    float s2 = sin(rad_pitch / 2);
    float c3 = cos(rad_yaw / 2);
    float s3 = sin(rad_yaw / 2);

    q[0] = c1 * c2 * c3 + s1 * s2 * s3; // w
    q[1] = c1 * c2 * s3 - s1 * s2 * c3; // x
    q[2] = s1 * c2 * c3 + c1 * s2 * s3; // y
    q[3] = c1 * s2 * c3 - s1 * c2 * s3; // z
}

chcnav_return_code_t
get_gimbal_information(CHCNAV_GIMBAL_INFORMATION_STRUCT *gimbal_information) {
  gimbal_information->uid = 0;
  gimbal_information->time_boot_ms = 0; // ToDo
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
  float yaw = 30;
  float pitch = 30;
  float roll = 0;
  system_state->time_boot_ms = 0;
  euler_anger_to_quaternion(pitch, yaw, roll, system_state->q);

  system_state->angular_velocity_x = NAN;
  system_state->angular_velocity_y = NAN;
  system_state->angular_velocity_z = NAN;
  system_state->failure_flags = 0;
  system_state->delta_yaw = NAN;
  system_state->delta_yaw_velocity = NAN;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_gimbal_attitude(CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT *attitude) {
  // set gimbal attitude
  if(!isnan(attitude->q[0]) && !isnan(attitude->q[1]) && !isnan(attitude->q[2]) && !isnan(attitude->q[3]))
  {
    float pitch, yaw, row;
    quaternion_to_euler_anger(pitch, yaw, row, attitude->q);
    printf("pitch:%f, yaw:%f, raw:%f\n", pitch, yaw, row);
    /* set gimbal attitude by angle. */
  }
  else if (!isnan(attitude->angular_velocity_x) && !isnan(attitude->angular_velocity_y) && !isnan(attitude->angular_velocity_z))
  {
    printf("velocity_x:%f, velocity_y:%f, velocity_z:%f\n", attitude->angular_velocity_x, attitude->angular_velocity_y, attitude->angular_velocity_z);
    /* set gimbal attitude by velocity. */
  }
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_gimbal_mode(CHCNAV_GIMBAL_MODE_E mode) {
  switch(mode)
  {
    case CHCNAV_GIMBAL_MODE_FREE:
      /* set gimbal mode to free. */
      printf("gimbal mode is CHCNAV_GIMBAL_MODE_FREE\n");
      break;
    case CHCNAV_GIMBAL_MODE_FPV:
      /* set gimbal mode to FPV. */
      printf("gimbal mode is CHCNAV_GIMBAL_MODE_FPV\n");
      break;
    case CHCNAV_GIMBAL_MODE_YAW_FOLLOW:
      /* set gimbal mode to yaw follow. */
      printf("gimbal mode is CHCNAV_GIMBAL_MODE_YAW_FOLLOW\n");
      break;
    case CHCNAV_GIMBAL_MODE_LOCK:
      /* set gimbal mode to lock. */
      printf("gimbal mode is CHCNAV_GIMBAL_MODE_LOCK\n");
      break;
    default:
      printf("Unknown mode:%d\n", mode);
      break;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_gimbal_mode(CHCNAV_GIMBAL_MODE_E *mode) {
  *mode = CHCNAV_GIMBAL_MODE_LOCK;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t reset_mode(CHCNAV_GIMBAL_RESET_MODE_E mode) {
  switch(mode)
  {
    case CHCNAV_GIMBAL_RESET_MODE_YAW:
      /* reset yaw axis of gimbal. */
      printf("gimbal reset mode is CHCNAV_GIMBAL_RESET_MODE_YAW\n");
      break;
    case CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW:
      /* Reset yaw axis and pitch axis of gimbal. */
      printf("gimbal reset mode is CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW\n");
      break;
    case CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD_AND_YAW:
      /* Reset yaw axis of gimbal, Set pitch axis downward. */
      printf("gimbal reset mode is CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD_AND_YAW\n");
      break;
    case CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD:
      /* Set pitch axis downward. */
      printf("gimbal reset mode is CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD\n");
      break;
    default:
      break;
  }
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t reset_factory_settings(void) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t set_gimbal_attitude_compansation_mode(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E mode)
{
  /* Set attitude compensation mode. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_gimbal_attitude_compansation_mode(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E *mode)
{
  *mode = CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_DISABLE;
  return CHCNAV_RETURN_OK;
}

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
  common_handler.set_gimbal_attitude_compansation_mode = set_gimbal_attitude_compansation_mode;
  common_handler.get_gimbal_attitude_compansation_mode = get_gimbal_attitude_compansation_mode;
  ret = chcnav_gimbal_register_common_handler(&common_handler);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "gimbal register common handler failed" << std::endl;
  }

  is_test_gimbal_inited = true;
  return CHCNAV_RETURN_OK;
}

void chcnav_test_gimbal_stop() {
  chcnav_gimbal_deinit();
  is_test_gimbal_inited = false;
}
bool chcnav_gimbal_is_inited() { return is_test_gimbal_inited; }