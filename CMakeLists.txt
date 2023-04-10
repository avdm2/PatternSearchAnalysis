cmake_minimum_required(VERSION 3.24)
project(StringSearchAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(StringSearchAnalysis main.cpp SearchMethods/NativeSearch.h)
