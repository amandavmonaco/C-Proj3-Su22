cmake_minimum_required(VERSION 3.16)
project(PA03_Anagrams)

set(CMAKE_CXX_STANDARD 14)

configure_file(data.txt data.txt COPYONLY)

add_executable(PA03_Anagrams main.cpp)
