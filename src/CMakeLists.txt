cmake_minimum_required(VERSION 3.23)
project(FrameNet C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(FrameNet src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h)
target_link_libraries(FrameNet ${CONAN_LIBS})
