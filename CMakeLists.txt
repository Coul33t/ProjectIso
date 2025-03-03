cmake_minimum_required(VERSION 3.14)
project(projectiso)

set(CMAKE_C_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# SDL2
IF (WIN32)
        SET(SDL3_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/SDL3/cmake") 
        SET(SDL3_Image_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/SDL3_image/cmake")
        SET(SDL3_ttf_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/SDL3_ttf/cmake") 
        FIND_PACKAGE(SDL3 REQUIRED) 
        FIND_PACKAGE(SDL3_Image REQUIRED)
        FIND_PACKAGE(SDL3_ttf REQUIRED)
ENDIF (WIN32)

IF (UNIX)
        # For Unix, you might need to do as follow: https://stackoverflow.com/a/67678616
        #list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl3)
        FIND_PACKAGE(SDL3 REQUIRED)
        FIND_PACKAGE(SDL3_image REQUIRED)
ENDIF (UNIX)


# Project code
INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src

        ${CMAKE_SOURCE_DIR}/extlib/random
        ${CMAKE_SOURCE_DIR}/extlib/json
)

FILE(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/include/entities/*.h"

        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/src/entities/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/entities/*.c"
)

#add_compile_options(-Wall -Wextra -Wpedantic)
ADD_EXECUTABLE(projectiso main.cpp ${all_SRCS})

IF (WIN32)
        TARGET_LINK_LIBRARIES(projectiso SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)
ENDIF (WIN32)

IF (UNIX)
        TARGET_LINK_LIBRARIES(projectiso SDL3 SDL3_image SDL3_ttf)
ENDIF (UNIX)