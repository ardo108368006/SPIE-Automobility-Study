cmake_minimum_required(VERSION 3.1)

project(scan_matching VERSION 1.0)

find_package(Eigen REQUIRED NO_MODULE)

set(CMAKE_CXX_STANDARD ll)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include "C:/Program Files/eigen-eigen/Eigen")
add_library(scan_matching_libs src/csv_reader.cpp)

add_executable(01_rigen_tester apps/01_egin_tester.cpp)