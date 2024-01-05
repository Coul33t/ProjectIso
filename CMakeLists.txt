cmake_minimum_required(VERSION 3.14)
project(projectiso)

set(CMAKE_C_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


# SDL2
IF (WIN32)
        SET(SDL2_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/SDL2/cmake") 
        SET(SDL2_Image_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/SDL2_image/cmake") 
        FIND_PACKAGE(SDL2 REQUIRED) 
        FIND_PACKAGE(SDL2_Image REQUIRED)
ENDIF (WIN32)

# TODO: Linux


# Project code
INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src

        ${CMAKE_SOURCE_DIR}/extlib/random
)

FILE(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
)


ADD_EXECUTABLE(projectiso main.cpp ${all_SRCS})
TARGET_LINK_LIBRARIES(projectiso SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image)