cmake_minimum_required(VERSION 3.4.1)
project(chcnav_psdk_demo CXX)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")
set(CMAKE_EXE_LINKER_FLAGS "-pthread")

if (NOT USE_SYSTEM_ARCH)
    add_definitions(-DSYSTEM_ARCH_LINUX)
endif ()

include_directories(
    ../../../modules_sample/payload_camera/
    ../../../modules_sample/camera_manager/
    ../../../modules_sample/gimbal_manager/
    ../../../modules_sample/gimbal/
    ../../../modules_sample/fc_subscription/
    ../../../modules_sample/widget/
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
    ../../../modules_sample/widget/*.cpp
)


add_executable(${PROJECT_NAME}
        ${GLOB_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/lib/x86_64-linux-gnu-gcc/libpayloadsdk.a)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/include)

set_target_properties( ${PROJECT_NAME}
   PROPERTIES
   OUTPUT_NAME               ${PROJECT_NAME}
   RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_INSTALL_BIN_RPATH}
)
