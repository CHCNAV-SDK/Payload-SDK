#include "file_binary_array_list_en.h"

#include "widget_file_c/en_big_screen/icon_button1_png.h"
#include "widget_file_c/en_big_screen/icon_button2_png.h"
#include "widget_file_c/en_big_screen/icon_list_item1_png.h"
#include "widget_file_c/en_big_screen/icon_list_item2_png.h"
#include "widget_file_c/en_big_screen/icon_scale_png.h"
#include "widget_file_c/en_big_screen/icon_switch_select_png.h"
#include "widget_file_c/en_big_screen/icon_switch_unselect_png.h"
#include "widget_file_c/en_big_screen/widget_config_json.h"

static CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT g_en_widget_file_binary_array_list[] = {
    {(char *)widget_config_json_file_name, widget_config_json_file_size,
     widget_config_json_file_binary_array},

    {(char *)icon_button1_png_file_name, icon_button1_png_file_size,
     icon_button1_png_file_binary_array},
    {(char *)icon_button2_png_file_name, icon_button2_png_file_size,
     icon_button2_png_file_binary_array},
    {(char *)icon_list_item1_png_file_name, icon_list_item1_png_file_size,
     icon_list_item1_png_file_binary_array},
    {(char *)icon_list_item2_png_file_name, icon_list_item2_png_file_size,
     icon_list_item2_png_file_binary_array},
    {(char *)icon_scale_png_file_name, icon_scale_png_file_size,
     icon_scale_png_file_binary_array},
    {(char *)icon_switch_select_png_file_name, icon_switch_select_png_file_size,
     icon_switch_select_png_file_binary_array},
    {(char *)icon_switch_unselect_png_file_name, icon_switch_unselect_png_file_size,
     icon_switch_unselect_png_file_binary_array},
};

uint32_t g_en_binary_array_count =
    sizeof(g_en_widget_file_binary_array_list) / sizeof(g_en_widget_file_binary_array_list[0]);
CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT *g_en_file_binary_array_list =
    g_en_widget_file_binary_array_list;
