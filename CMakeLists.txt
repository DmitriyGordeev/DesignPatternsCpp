cmake_minimum_required(VERSION 3.20)
project(DesignPatternsCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(creational/)

add_executable(DesignPatternsCpp main.cpp creational/singleton.h)
