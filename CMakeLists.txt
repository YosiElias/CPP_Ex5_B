cmake_minimum_required(VERSION 3.21)
project(Part_A)

set(CMAKE_CXX_STANDARD 14)

add_executable(Part_A OrgChart.hpp Demo.cpp sources/OrgChart.cpp sources/Man.hpp sources/Man.cpp TestCounter.cpp Test.cpp)
