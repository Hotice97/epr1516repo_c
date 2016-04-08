cmake_minimum_required(VERSION 3.3)
project(epr1516repo_c)

find_library (LIBSTDCXX stdc++)
add_compile_options(-stdlib=libstdc++)
target_link_libraries(${epr1516repo_c} ${LIBSTDCXX})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -stdlib=libstdc++")


#set(SOURCE_FILES main.cpp)
#set(SOURCE_FILES ooa/test/main.c)
set(SOURCE_FILES ooa/praktikum1/main.c)
add_executable(epr1516repo_c ${SOURCE_FILES})