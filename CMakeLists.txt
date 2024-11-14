cmake_minimum_required(VERSION 3.20)
project(tensorflow-app)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Paths to libraries
set(OpenCV_DIR "/home/torizon/lib/opencv/build")
set(TFLITE_DIR "/home/torizon/lib/tensorflow")

set(TFLITE_C_LIB_PATH "/home/torizon/lib/tensorflow/tensorflow/lite/build-c")
set(TFLITE_C_INCLUDE_PATH "/home/torizon/lib/tensorflow/tensorflow/lite")

# enable xsimd
add_definitions(-DXTENSOR_USE_XSIMD=1)

# find packages
find_package(OpenCV REQUIRED)
find_package(xtensor REQUIRED)

message(STATUS "TFLITE_ENABLE_GPU: ${TFLITE_ENABLE_GPU}")
message(STATUS "TFLITE_ENABLE_XNNPACK: ${TFLITE_ENABLE_XNNPACK}")
message(STATUS "TFLITE_DELEGATE: ${TFLITE_DELEGATE}")

include_directories(
    ${TFLITE_DIR}
    ${TFLITE_C_INCLUDE_PATH}
    ${EXTERNAL_DELEGATE_PATH}
    include
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(tensorflow-app ${SOURCES})

target_link_libraries(tensorflow-app PRIVATE 
    ${OpenCV_LIBS}           # OpenCV libraries
    ${TFLITE_C_LIB_PATH}/libtensorflowlite_c.so
    xtensor                  # xtensor library
)
target_compile_options(tensorflow-app PRIVATE -march=native)
