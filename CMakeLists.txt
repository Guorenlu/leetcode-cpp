cmake_minimum_required(VERSION 3.10)
project(leetcode_cpp)
set(CMAKE_CXX_STANDARD 17)

# 获取 src 目录下所有一级子目录
file(GLOB PROBLEM_DIRS LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR}/src "${CMAKE_SOURCE_DIR}/src/*")

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    # 过滤只保留目录
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/src/${PROBLEM_DIR}")
        # 收集该目录下所有 cpp 文件
        file(GLOB PROBLEM_SRCS "${CMAKE_SOURCE_DIR}/src/${PROBLEM_DIR}/*.cpp")

        # 添加可执行文件，名字就是子目录名，源码就是该目录所有 cpp
        add_executable(${PROBLEM_DIR} ${PROBLEM_SRCS})

        # 包含头文件路径
        target_include_directories(${PROBLEM_DIR} PRIVATE "${CMAKE_SOURCE_DIR}/src/${PROBLEM_DIR}")
    endif()
endforeach()
