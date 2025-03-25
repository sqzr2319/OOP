cmake_minimum_required(VERSION 3.10)
project(HW13)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 添加可执行文件
add_executable(HW13
    src/main.cpp
    src/NodeFactory.cpp
    src/StudentList.cpp
)