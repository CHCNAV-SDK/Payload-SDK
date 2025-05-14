cmake_minimum_required(VERSION 3.4.1)
project(chcnav_psdk_demo CXX)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")
set(CMAKE_EXE_LINKER_FLAGS "-pthread")

include_directories(
    ../../../modules_sample/payload_camera/
    ../../../modules_sample/camera_manager/
    ../../../modules_sample/gimbal_manager/
    ../../../modules_sample/gimbal/
    ../../../modules_sample/fc_subscription/
)

file(GLOB GLOB_SRCS
    main.cpp
    hal/*.cpp
    osal/*.cpp
    ../../../modules_sample/payload_camera/*.cpp
    ../../../modules_sample/camera_manager/*.cpp
    ../../../modules_sample/gimbal_manager/*.cpp
    ../../../modules_sample/gimbal/*.cpp
    ../../../modules_sample/fc_subscription/*.c
)


add_executable(${PROJECT_NAME}
        ${GLOB_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/lib/x86_64-linux-gnu-gcc/libpayloadsdk.a)
#add_dependencies(${PROJECT_NAME} payloadsdk)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/include)

set_target_properties( ${PROJECT_NAME}
   PROPERTIES
   OUTPUT_NAME               ${PROJECT_NAME}
   RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}
)
