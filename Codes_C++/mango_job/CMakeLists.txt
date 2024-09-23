cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MangoProcessing)

# 设置 C++ 标准为 C++11 或更高
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 添加可执行文件
add_executable(mango_processing main.cpp) # main.cpp 为你的源文件

# 链接 OpenCV 库
target_link_libraries(mango_processing ${OpenCV_LIBS})

# 为输出文件添加详细信息
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
