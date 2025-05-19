cmake_minimum_required(VERSION 3.10)
project(video_to_ascii)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})
add_executable(output video_to_ascii.cpp)
target_link_libraries(output ${OpenCV_LIBS})

