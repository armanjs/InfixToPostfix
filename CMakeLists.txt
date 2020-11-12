cmake_minimum_required(VERSION 3.16)
project(InfixToPostfix)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfixToPostfix main.cpp InfixToPostfix.h InfixToPostfix.cpp stackArray.h stackArray.cpp mathExp.h mathExp.cpp)