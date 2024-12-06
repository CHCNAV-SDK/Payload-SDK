#ifndef TEST_PAYLOAD_CAMERA_H
#define TEST_PAYLOAD_CAMERA_H

#include "chcnav_error.h"
#include "chcnav_payload_camera.h"
#include "chcnav_typedef.h"

namespace chcnav {
namespace psdk {
namespace modules_sample {

class TestPayloadCamera final {
public:
  static TestPayloadCamera &get_instance() {
    static TestPayloadCamera test_payload_camera;
    return test_payload_camera;
  }
  bool chcnav_test_payload_camera_is_inited();
  chcnav_return_code_t chcnav_test_payload_camera_start();

private:
  TestPayloadCamera() = default;
  ~TestPayloadCamera() = default;
  TestPayloadCamera(const TestPayloadCamera &) = delete;
  TestPayloadCamera &operator=(const TestPayloadCamera &) = delete;

private:
  bool is_test_payload_camera_inited{false};
};
} // namespace modules_sample
} // namespace psdk
} // namespace chcnav

#endif