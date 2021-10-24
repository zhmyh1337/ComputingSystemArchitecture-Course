cmake_minimum_required (VERSION 3.8)

project (hw2)
set (CMAKE_CXX_STANDARD 20)

add_executable (program "main.cpp" "container.cpp" "container.h" "input_helper.cpp" "input_helper.h" "plane.cpp" "plane.h" "ship.cpp" "ship.h" "train.cpp" "train.h" "base_transport.cpp" "base_transport.h" "random.h" "random.cpp")
