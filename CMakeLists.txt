cmake_minimum_required(VERSION 3.20)
project(DesignPatternsCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(creational/)
include_directories(structural/)
include_directories(behavioral/)

file(GLOB CREATIONAL_SRC
        creational/*.h)

file(GLOB STRUCTURAL_SRC
        structural/*.h)

file(GLOB BEHAVIORAL_SRC
        behavioral/*.h)

add_executable(DesignPatternsCpp main.cpp
        ${CREATIONAL_SRC}
        ${STRUCTURAL_SRC}
        ${BEHAVIORAL_SRC})
