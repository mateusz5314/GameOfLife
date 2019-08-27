cmake_minimum_required(VERSION 2.6)

project(GameOfLife)

include_directories(include)

add_executable(GameOfLife 
    src/main.cpp
    src/mechanic.cpp
    include/mechanic.hpp
)