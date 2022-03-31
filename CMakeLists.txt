cmake_minimum_required(VERSION 3.14)
project(projectiso)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")

# raylib is there
INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src

        ${CMAKE_SOURCE_DIR}/extlib/random
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(projectiso main.cpp ${all_SRCS} include/map.h src/map.cpp main.cpp include/types.h include/tools.h src/tools.cpp include/renderer.h src/renderer.cpp)

TARGET_LINK_LIBRARIES(projectiso libraylib.so)