# 指定cmake版本 
cmake_minimum_required(VERSION 3.6)

# 项目的名称，一般和项目的文件夹名称对应
PROJECT(jmat)

# 添加头文件搜索路径
INCLUDE_DIRECTORIES(D:\\Library\\Eigen\\Eigen)

# 添加lib搜索路径
# LINK_DIRECTORIES(${HELLO_SOURCE_DIR}\\lib)

# set 命令用来设置变量
set(CMAKE_C_COMPILER     g++)
set(CMAKE_CXX_COMPILER   g++)
set(CMAKE_CXX_STANDARD   14)
set(SOURCE_FILES         main.cpp Mat.cpp Mat.h)

# add_exectuable 告诉工程生成一个可执行文件，add_library 则告诉生成一个库文件
add_executable(jmat ${SOURCE_FILES})