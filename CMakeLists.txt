cmake_minimum_required(VERSION 3.22)
project(my_thread_pool)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_thread_pool main.cpp ThreadPool.cpp ThreadPool.h)
