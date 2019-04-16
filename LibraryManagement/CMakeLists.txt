cmake_minimum_required(VERSION 3.13)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagement main.cpp Book.h Book.cpp Customer.h Customer.cpp Library.h Library.cpp)