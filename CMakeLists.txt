cmake_minimum_required(VERSION 3.20)
project(LearningOpenCV)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearningOpenCV main.cpp Demo.cpp Demo.h Learning.cpp Learning.h)

set(OpenCV_DIR F:/Opencv/opencv/source-build)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(LearningOpenCV ${OpenCV_LIBS} )