cmake_minimum_required(VERSION 3.13)
project(LibraryManagementImproved)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagementImproved main.cpp Book.h Book.cpp Customer.h Customer.cpp Library.h Library.cpp)