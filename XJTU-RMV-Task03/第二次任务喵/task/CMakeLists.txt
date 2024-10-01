cmake_minimum_required(VERSION 3.0.0)
project(task)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})

set(SRC_FILES main.cpp ./src/windmill.cpp)

add_executable(task ${SRC_FILES})
target_link_libraries(task ${OpenCV_LIBS} ${CERES_LIBRARIES})