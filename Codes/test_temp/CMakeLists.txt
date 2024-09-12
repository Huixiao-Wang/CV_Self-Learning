cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Class_test)

# 设置 C++ 标准为 C++11 或更高
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(Class_test main.cpp) # main.cpp 为你的源文件
