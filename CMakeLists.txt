cmake_minimum_required(VERSION 3.23)
project(boomer)

set(CMAKE_CXX_STANDARD 23)

set(Engine
        engine/Field.cpp
        engine/Game.cpp)

add_executable(boomer main.cpp ${Engine})
