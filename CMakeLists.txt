cmake_minimum_required(VERSION 3.3)
project(epr1516repo_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

#set(SOURCE_FILES main.cpp)
#set(SOURCE_FILES pratika1/praktikas3.c)
set(SOURCE_FILES pratika1/martikelnummern.c)
add_executable(epr1516repo_c ${SOURCE_FILES})