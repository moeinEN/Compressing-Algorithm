cmake_minimum_required(VERSION 3.30)
project(Compressing_Algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compressing_Algorithm main.cpp
        bwt.cpp
        bwt.h
        runLength.cpp
        runLength.h
        huffman.cpp
        huffman.h
)
