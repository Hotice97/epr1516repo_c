CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
PROJECT(HELPER C CXX)
SET(CMAKE_VERBOSE_MAKEFILE ON)
# Create empty static C++ helper library:
FILE(WRITE ${CMAKE_BINARY_DIR}/helper.cxx "")
ADD_LIBRARY(helper STATIC helper.cxx)
# Create badly linked bar library:
FILE(WRITE ${CMAKE_BINARY_DIR}/bar.cxx
"#include <iostream>
extern \"C\" void bar(void){std::cout<<\"FooBar!\\n\";}\n")
EXECUTE_PROCESS(COMMAND g++ -c bar.cxx)
EXECUTE_PROCESS(COMMAND g++ -shared -nodefaultlibs -o libbar.so bar.o)
# Import it and make it depend on helper:
ADD_LIBRARY(bar SHARED IMPORTED)
SET_TARGET_PROPERTIES(bar PROPERTIES
    IMPORTED_LOCATION libbar.so
    IMPORTED_LINK_INTERFACE_LIBRARIES helper
)
ADD_DEPENDENCIES(bar helper)
# Create C target foo depending on bar:
FILE(WRITE ${CMAKE_BINARY_DIR}/foo.c
"int main(void){bar(); return 0;}\n")
ADD_EXECUTABLE(foo foo.c)
TARGET_LINK_LIBRARIES(foo bar)
SET_TARGET_PROPERTIES(foo PROPERTIES LINKER_LANGUAGE C)