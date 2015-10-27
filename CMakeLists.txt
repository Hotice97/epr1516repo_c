cmake_minimum_required(VERSION 3.3)
project(epr1516repo_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp)
#set(SOURCE_FILES pratika1/praktika1.cpp)
set(SOURCE_FILES pratika1/c_praktika1.c)
add_executable(epr1516repo_c ${SOURCE_FILES})