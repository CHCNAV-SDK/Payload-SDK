#include "test_payload_camera.h"
#include "chcnav_payload_camera.h"
#include <iostream>

static CHCNAV_CAMERA_EXPOSURE_MODE_E g_camera_exposure_mode = CHCNAV_CAMERA_EXPOSURE_MODE_SHUTTER_PRIORITY;
static uint32_t g_camera_iso = 100;
static float g_camera_aperture = 80;
static uint32_t g_camera_shutter_speed = 30;
static float g_camera_ev = 1.0;
static float g_camera_zoom = 1.0;
static float g_camera_focus = 50;

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

chcnav_return_code_t
get_camera_information(CHCNAV_CAMERA_INFORMATION_STRUCT *camera_information) {
  camera_information->storage_count = 6;
  camera_information->firmware_version = 0x1;
  camera_information->focal_length = 50.000000;
  camera_information->sensor_size_h = 48.639999;
  camera_information->sensor_size_v = 40.380001;
  camera_information->flags = 4;
  camera_information->resolution_h = 11648;
  camera_information->resolution_v = 8736;
  camera_information->cam_definition_version = 1;
  snprintf((char *)camera_information->vendor_name,
           sizeof(camera_information->vendor_name), "CHCNAV");
  snprintf((char *)camera_information->model_name,
           sizeof(camera_information->model_name), "C10");
  snprintf((char *)camera_information->cam_definition_uri,
           sizeof(camera_information->cam_definition_uri),
           "http://192.168.1.102:8554/caminfo.xml");
  camera_information->lens_id = 0;
  camera_information->camera_type = CHCNAV_CAMERA_TYPE_TELEPHOTO;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_camera_state(CHCNAV_CAMERA_SYSTEM_STATE_STRUCT *system_state) {
  system_state->temperature = 41.2;
  system_state->camera_mode = CHCNAV_CAMERA_MODE_IMAGE;
  system_state->zoom_level = 2.3;
  system_state->focus_level = 1.2;
  system_state->capturing_state = CHCNAV_CAMERA_CAPTURING_PHOTO_IDLE;
  system_state->is_capturing = false;
  system_state->is_capturing_interval_start = false;
  system_state->image_capturing_interval_time_seconds = 0;
  system_state->image_capturing_interval_count = 10;
  system_state->image_capturing_history_count = 200;
  system_state->is_recording = false;
  system_state->video_recording_time_seconds = 100;
  system_state->has_error = false;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_sn(CHCNAV_CAMERA_SN_STRUCT *camera_sn) {
  snprintf((char *)camera_sn->serial_number, sizeof(camera_sn->serial_number),"C30Ch_5.13.002.14.0C30.25");
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_camera_capability(CHCNAV_CAMERA_CAP_STRUCT *camera_cap) {
  camera_cap->zoom_flag = 1;
  camera_cap->focus_flag = 1;
  camera_cap->ircut_flag = 1;
  camera_cap->exposure_mode_flag = 1 ;
  camera_cap->iso_flag = 1;
  camera_cap->aperture_flag = 1;
  camera_cap->shutter_flag = 1;
  camera_cap->ev_flag = 1;
  camera_cap->meter_flag = 1;
  camera_cap->wb_mode_flag = 1;
  camera_cap->antiflicker_flag = 1;
  camera_cap->brightness_flag = 1;
  camera_cap->saturation_flag = 1;
  camera_cap->contrast_flag = 1;
  camera_cap->sharpness_flag = 1;
  camera_cap->color_mode_flag = 1;
  camera_cap->video_encode_flag = 1;
  camera_cap->video_format_flag = 1;
  camera_cap->video_media_flag = 1;
  camera_cap->photo_format_flag = 1;
  camera_cap->photo_ratio_flag = 1;
  camera_cap->photo_quality_flag = 1;
  camera_cap->battery_flag = 1;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_camera_mode(CHCNAV_CAMERA_MODE_E mode) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_mode(CHCNAV_CAMERA_MODE_E *mode) {
  *mode = CHCNAV_CAMERA_MODE_IMAGE;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t start_capture_image() { return CHCNAV_RETURN_OK; }
chcnav_return_code_t stop_capture_image() { return CHCNAV_RETURN_OK; }
chcnav_return_code_t set_capture_image_mode(CHCNAV_CAMERA_CAPTURE_MODE_E mode) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_capture_image_mode(CHCNAV_CAMERA_CAPTURE_MODE_E *mode) {
  *mode = CHCNAV_CAMERA_CAPTURE_MODE_SINGLE;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_image_time_interval_settings(
    CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT settings) {
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t get_image_time_interval_settings(
    CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT *settings) {
  settings->capture_count = 100;
  settings->time_interval_seconds = 1;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_video_stream_information(uint8_t stream_id,CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT *video_stream_info) {
  video_stream_info->stream_id = 1;
  video_stream_info->count = 1;
  video_stream_info->type = CHCNAV_CAMERA_VIDEO_STREAM_TYPE_RTSP;
  video_stream_info->flags = CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_RUNNING;
  video_stream_info->framerate = 30;
  video_stream_info->resolution_h = 1920;
  video_stream_info->resolution_v = 1080;
  video_stream_info->bitrate = 1 * 1024 * 1024;
  video_stream_info->rotation = 0;
  video_stream_info->hfov = 90;
  snprintf((char *)video_stream_info->name, sizeof(video_stream_info->name), "test_stream");
  snprintf((char *)video_stream_info->uri, sizeof(video_stream_info->uri), "rtsp://admin:admin@192.168.1.101:554/1/live");
  video_stream_info->encoding = CHCNAV_CAMERA_VIDEO_ENCODING_H264;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_video_stream_status(
    uint8_t stream_id,
    CHCNAV_CAMERA_VIDEO_STREAM_STATUS_STRUCT *video_stream_status) {

  video_stream_status->flags = CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_RUNNING;
  video_stream_status->framerate = 15;
  video_stream_status->resolution_h = 1920;
  video_stream_status->resolution_v = 1080;
  video_stream_status->bitrate = 30;
  video_stream_status->rotation = 10;
  video_stream_status->hfov = 10;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t start_record_video() { return CHCNAV_RETURN_OK; }
chcnav_return_code_t stop_record_video() { return CHCNAV_RETURN_OK; }
chcnav_return_code_t
get_sd_card_state(uint8_t storage_id,
                  CHCNAV_CAMERA_SDCARD_STATE_STRUCT *sd_card_state) {
  sd_card_state->storage_id = storage_id;
  sd_card_state->storage_count = 6;
  sd_card_state->status = CHCNAV_CAMERA_SDCARD_STATUS_READY;
  sd_card_state->storage_usage = CHCNAV_CAMERA_SDCARD_USAGE_FLAG_PHOTO;
  sd_card_state->total_capacity_mb = 250.0;
  sd_card_state->used_capacity_mb = 1.0;
  sd_card_state->available_capacity_mb = 249.0;
  sd_card_state->read_speed_mb_per_second = 128;
  sd_card_state->write_speed_mb_per_second = 128;
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t format_sd_card(uint8_t storage_id) {
  /* format SD Card. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t reset_system_settings() { return CHCNAV_RETURN_OK; }

chcnav_return_code_t set_exposure_mode(CHCNAV_CAMERA_EXPOSURE_MODE_E mode) {

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_exposure_mode(CHCNAV_CAMERA_EXPOSURE_MODE_E *mode) {
  *mode = g_camera_exposure_mode;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_shutter_speed(uint32_t *value) {
  *value = g_camera_shutter_speed;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_aperture(float *value) {
  *value = g_camera_aperture;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_iso(uint32_t *value) {
  *value = g_camera_iso;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_ev(float *value) {
  *value = g_camera_ev;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_metering_mode(CHCNAV_CAMERA_METERING_MODE_E mode) {

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_metering_mode(CHCNAV_CAMERA_METERING_MODE_E *mode) {
  *mode = CHCNAV_CAMERA_METERING_MODE_CENTER;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_spot_metering_range(CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT *range) {
  range->col = 25;
  range->row = 15;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_spot_metering_target(CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT *target) {
  target->col = 20;
  target->row = 30;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_white_balance_mode(CHCNAV_CAMERA_WHITE_BALANCE_MODE_E mode) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_white_balance_mode(CHCNAV_CAMERA_WHITE_BALANCE_MODE_E *mode) {
  *mode = CHCNAV_CAMERA_WHITE_BALANCE_MODE_SUNSET;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_brightness(uint8_t value) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t get_brightness(uint8_t *value) {
  *value = 80;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_saturation(uint8_t value) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t get_saturation(uint8_t *value) {
  *value = 80;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_contrast(uint8_t value) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t get_contrast(uint8_t *value) {
  *value = 80;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_sharpness(uint8_t value) { return CHCNAV_RETURN_OK; }

chcnav_return_code_t get_sharpness(uint8_t *value) {
  *value = 80;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_color_mode(CHCNAV_CAMERA_COLOR_MODE_E mode) {

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_color_mode(CHCNAV_CAMERA_COLOR_MODE_E *mode) {
  *mode = CHCNAV_CAMERA_COLOR_MODE_ENHANCED;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_capture_interval(uint32_t *value) {
  *value = 1000;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_picture_format(CHCNAV_CAMERA_PICTURE_FORMAT_E format) {

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_picture_format(CHCNAV_CAMERA_PICTURE_FORMAT_E *format) {

  *format = CHCNAV_CAMERA_PICTURE_FORMAT_JPEG;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_picture_quality(CHCNAV_CAMERA_PICTURE_QUALITY_E value) {
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t
get_picture_quality(CHCNAV_CAMERA_PICTURE_QUALITY_E *value) {
  *value = CHCNAV_CAMERA_PICTURE_QUALITY_HIGH;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_video_encode_format(CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E value) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_video_encode_format(CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E *value) {
  *value = CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_H264;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
set_video_record_format(CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E value) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t
get_video_record_format(CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E *value) {

  *value = CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_MP4;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_media_config(CHCNAV_CAMERA_CONFIG_STRUCT config) {
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_media_config(CHCNAV_CAMERA_CONFIG_STRUCT *config) {
  config->width = 11648;
  config->height = 8736;
  config->framerate = 30;
  config->bitrate = 25;

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_digicam_config(CHCNAV_CAMERA_EXPOSURE_MODE_E exposure_mode,uint32_t shutter_speed,float aperture,uint32_t iso,float exposure_compensation_value) {
  // do digicam config
  g_camera_exposure_mode = exposure_mode;
  g_camera_shutter_speed = shutter_speed;
  g_camera_aperture = aperture;
  g_camera_iso = iso;
  g_camera_ev = exposure_compensation_value;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_camera_source(uint8_t device_id, CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_E video_stream_source) {
  printf("set video stream source is :%d\n", video_stream_source);
  switch (video_stream_source)
  {
    case CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_TELEPHOTO:
      /* Modify RTSP stream to telephoto camera stream data. */
      break;
    case CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_WIDE_ANGLE:
      /* Modify RTSP stream to wide-angle camera stream data. */
      break;
    case CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_INFRARED:
      /* Modify RTSP stream to infrared camera stream data. */
      break;
    case CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_PIP:
      /* Modify RTSP stream to PIP stream data. */
      break;
    default:
      break;
  }

  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_camera_track_point(float x,float y,float radius,uint8_t device_id) {
  // set camera track point
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t set_camera_ir_mode(CHCNAV_CAMERA_IR_MODE_E mode) {
  // set camera ir mode
  printf("set infrared color mode:%d\n", mode);
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t get_camera_ir_mode(CHCNAV_CAMERA_IR_MODE_E *mode){
  *mode = CHCNAV_CAMERA_IR_MODE_WHITE_HOT;
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t set_stream_osd(CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT osd_config) {
  // set stream osd config
  printf("osd enable:%u, pitch_yaw_enable:%u, center_cross_enable:%u,time_enable:%u, range_enable:%u, gps_coordinates:%u, temperature_enable:%u\n",
    osd_config.osd_enable, osd_config.pitch_yaw_enable, osd_config.center_cross_enable, osd_config.time_enable,
    osd_config.range_enable, osd_config.gps_coordinates, osd_config.temperature_enable);
  return CHCNAV_RETURN_OK;
}
chcnav_return_code_t get_stream_osd(CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT *osd_config) {
  osd_config->osd_enable = CHCNAV_STREAM_OSD_OPEN;
  osd_config->pitch_yaw_enable = CHCNAV_STREAM_OSD_OPEN;
  osd_config->center_cross_enable = CHCNAV_STREAM_OSD_CLOSED;
  osd_config->time_enable = CHCNAV_STREAM_OSD_CLOSED;
  osd_config->range_enable = CHCNAV_STREAM_OSD_CLOSED;
  osd_config->gps_coordinates = CHCNAV_STREAM_OSD_CLOSED;
  osd_config->temperature_enable = CHCNAV_STREAM_OSD_CLOSED;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_iso_list(uint16_t *count, uint16_t *capability){
  *count = 6;
  capability[0] = 100;
  capability[1] = 200;
  capability[2] = 400;
  capability[3] = 800;
  capability[4] = 1600;
  capability[5] = 3200;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_shutter_list(uint16_t *count, uint16_t *capability){
  *count = 8;
  capability[0] = 1000; //shutter = 1/1000 s
  capability[1] = 800;  //shutter = 1/800 s
  capability[2] = 500;  //shutter = 1/500 s
  capability[3] = 200;  //shutter = 1/200 s
  capability[4] = 100;  //shutter = 1/100 s
  capability[5] = 40;   //shutter = 1/40 s
  capability[6] = 30;   //shutter = 1/30 s
  capability[7] = 15;   //shutter = 1/15 s
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_ir_color_list(uint16_t *count, uint16_t *capability)
{
  *count = 3;
  capability[0] = CHCNAV_CAMERA_IR_MODE_WHITE_HOT;
  capability[1] = CHCNAV_CAMERA_IR_MODE_BLACK_HOT;
  capability[2] = CHCNAV_CAMERA_IR_MODE_RAINBOW;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_zoom_configure(CHCNAV_CAMERA_ZOOM_CONFIGURE_STRUCT* zoom_config)
{
  zoom_config->zoom = g_camera_zoom;
  zoom_config->zoom_max = 30;
  zoom_config->camera_type = CHCNAV_CAMERA_TYPE_TELEPHOTO;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_zoom_step(CHCNAV_CAMERA_ZOOM_DIRECTION_E direction)
{
  if (direction == CHCNAV_CAMERA_ZOOM_DIRECTION_IN)
  {
    /* Single step zoom in by 0.1x. */
  }
  else if (direction == CHCNAV_CAMERA_ZOOM_DIRECTION_OUT)
  {
    /* Single step zoom out by 0.1x. */
  }
  else
    return CHCNAV_PAYLOAD_CAMERA_ERROR_INVALID_COMMAND_PARAMETER;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_continuous_zoom_start(CHCNAV_CAMERA_ZOOM_DIRECTION_E direction)
{
  if (direction == CHCNAV_CAMERA_ZOOM_DIRECTION_IN)
  {
    /* continuous zoom in until get stop. */
  }
  else if (direction == CHCNAV_CAMERA_ZOOM_DIRECTION_OUT)
  {
    /* ontinuous zoom out until get stop. */
  }
  else
    return CHCNAV_PAYLOAD_CAMERA_ERROR_INVALID_COMMAND_PARAMETER;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_continuous_zoom_stop()
{
  /* Stop continuous zoom if continuous zoom was started. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_zoom_by_value(float factor)
{
  /* Set the zoom according to the value of factor. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t get_camera_focus_configure(CHCNAV_CAMERA_FOCUS_CONFIGURE_STRUCT* focus_configs)
{
  focus_configs->focus = g_camera_focus;
  focus_configs->focus_min = 0;
  focus_configs->focus_max = 100;
  focus_configs->camera_type = CHCNAV_CAMERA_TYPE_TELEPHOTO;
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_manual_focus(float value)
{
  /* Set the focus according to the value. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t camera_auto_continuous_focus()
{
  /* Set to automatic continuous zoom. */
  return CHCNAV_RETURN_OK;
}

chcnav_return_code_t TestPayloadCamera::chcnav_test_payload_camera_start() {
  chcnav_return_code_t ret = CHCNAV_RETURN_ERR_FAILURE;

  CHCNAV_CAMERA_COMMON_HANDLER_STRUCT common_handler_st{};
  common_handler_st.get_camera_information = get_camera_information;
  common_handler_st.get_camera_state = get_camera_state;
  common_handler_st.get_camera_sn = get_camera_sn;
  common_handler_st.get_camera_capability = get_camera_capability;
  common_handler_st.set_camera_mode = set_camera_mode;
  common_handler_st.get_camera_mode = get_camera_mode;
  common_handler_st.start_capture_image = start_capture_image;
  common_handler_st.stop_capture_image = stop_capture_image;
  common_handler_st.set_capture_image_mode = set_capture_image_mode;
  common_handler_st.get_capture_image_mode = get_capture_image_mode;
  common_handler_st.set_image_time_interval_settings =
      set_image_time_interval_settings;
  common_handler_st.get_image_time_interval_settings =
      get_image_time_interval_settings;

  common_handler_st.get_video_stream_information = get_video_stream_information;
  common_handler_st.get_video_stream_status = get_video_stream_status;
  common_handler_st.start_record_video = start_record_video;
  common_handler_st.stop_record_video = stop_record_video;
  common_handler_st.get_sd_card_state = get_sd_card_state;
  common_handler_st.format_sd_card = format_sd_card;
  common_handler_st.reset_system_settings = reset_system_settings;

  ret = chcnav_payload_camera_register_common_handler(&common_handler_st);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_payload_camera_register_common_handler failed"
              << std::endl;
    return ret;
  }

  CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT parameter_handler_st{};
  parameter_handler_st.set_exposure_mode = set_exposure_mode;
  parameter_handler_st.get_exposure_mode = get_exposure_mode;
  parameter_handler_st.get_shutter_speed = get_shutter_speed;
  parameter_handler_st.get_aperture = get_aperture;
  parameter_handler_st.get_iso = get_iso;
  parameter_handler_st.get_ev = get_ev;
  parameter_handler_st.set_metering_mode = set_metering_mode;
  parameter_handler_st.get_metering_mode = get_metering_mode;
  parameter_handler_st.get_spot_metering_range = get_spot_metering_range;
  parameter_handler_st.get_spot_metering_target = get_spot_metering_target;
  parameter_handler_st.set_white_balance_mode = set_white_balance_mode;
  parameter_handler_st.get_white_balance_mode = get_white_balance_mode;
  parameter_handler_st.set_brightness = set_brightness;
  parameter_handler_st.get_brightness = get_brightness;
  parameter_handler_st.set_saturation = set_saturation;
  parameter_handler_st.get_saturation = get_saturation;
  parameter_handler_st.set_contrast = set_contrast;
  parameter_handler_st.get_contrast = get_contrast;
  parameter_handler_st.set_sharpness = set_sharpness;
  parameter_handler_st.get_sharpness = get_sharpness;
  parameter_handler_st.set_color_mode = set_color_mode;
  parameter_handler_st.get_color_mode = get_color_mode;
  parameter_handler_st.get_capture_interval = get_capture_interval;
  parameter_handler_st.set_picture_format = set_picture_format;
  parameter_handler_st.get_picture_format = get_picture_format;
  parameter_handler_st.set_picture_quality = set_picture_quality;
  parameter_handler_st.get_picture_quality = get_picture_quality;
  parameter_handler_st.set_video_encode_format = set_video_encode_format;
  parameter_handler_st.get_video_encode_format = get_video_encode_format;
  parameter_handler_st.set_video_record_format = set_video_record_format;
  parameter_handler_st.get_video_record_format = get_video_record_format;
  parameter_handler_st.set_media_config = set_media_config;
  parameter_handler_st.get_media_config = get_media_config;
  parameter_handler_st.set_digicam_config = set_digicam_config;
  parameter_handler_st.set_camera_source = set_camera_source;
  parameter_handler_st.set_camera_track_point = set_camera_track_point;
  parameter_handler_st.set_camera_ir_mode = set_camera_ir_mode;
  parameter_handler_st.get_camera_ir_mode = get_camera_ir_mode;
  parameter_handler_st.set_stream_osd = set_stream_osd;
  parameter_handler_st.get_stream_osd = get_stream_osd;
  parameter_handler_st.get_camera_iso_list = get_camera_iso_list;
  parameter_handler_st.get_camera_shutter_list = get_camera_shutter_list;
  parameter_handler_st.get_camera_ir_color_list = get_camera_ir_color_list;

  ret = chcnav_payload_camera_register_parameter_handler(&parameter_handler_st);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_payload_camera_register_parameter_handler failed"
              << std::endl;
    return ret;
  }

  CHCNAV_CAMERA_ZOOM_HANDLER_STRUCT zoom_handler_st{0};
  zoom_handler_st.camera_zoom_step = camera_zoom_step;
  zoom_handler_st.camera_continuous_zoom_start = camera_continuous_zoom_start;
  zoom_handler_st.camera_continuous_zoom_stop = camera_continuous_zoom_stop;
  zoom_handler_st.camera_zoom_by_value = camera_zoom_by_value;
  zoom_handler_st.get_camera_zoom_configure = get_camera_zoom_configure;
  ret = chcnav_camera_zoom_handler(&zoom_handler_st);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_camera_zoom_handler failed" << std::endl;
    return ret;
  }

  CHCNAV_CAMERA_FOCUS_HANDLER_STRUCT focus_handle_st{0};
  focus_handle_st.camera_manual_focus = camera_manual_focus;
  focus_handle_st.camera_auto_continuous_focus = camera_auto_continuous_focus;
  focus_handle_st.get_camera_focus_configure = get_camera_focus_configure;
  ret = chcnav_camera_focus_handler(&focus_handle_st);
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_camera_focus_handler failed" << std::endl;
    return ret;
  }

  ret = chcnav_payload_camera_init();
  if (ret != CHCNAV_RETURN_OK) {
    std::cout << "chcnav_payload_camera_init failed" << std::endl;
    return ret;
  }
  ret = is_test_payload_camera_inited = true;
  return CHCNAV_RETURN_OK;
}

bool TestPayloadCamera::chcnav_test_payload_camera_is_inited() {
  return is_test_payload_camera_inited;
}

void chcnav_run_payload_camera_sample(void)
{
	chcnav_return_code_t ret;
	ret = TestPayloadCamera::get_instance().chcnav_test_payload_camera_start();
		if (ret != CHCNAV_RETURN_OK) {
		return;
	}
}

void chcnav_stop_payload_camera_sample(void)
{
  chcnav_payload_camera_deinit();
}
