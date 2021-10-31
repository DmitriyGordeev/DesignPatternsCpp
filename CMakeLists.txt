cmake_minimum_required(VERSION 3.20)
project(DesignPatternsCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(creational/)
include_directories(structural/)

add_executable(DesignPatternsCpp main.cpp
        creational/factory.h
        creational/singleton.h
        structural/adapter.h
        structural/decorator.h
        structural/proxy.h
        structural/flyweight.h)
