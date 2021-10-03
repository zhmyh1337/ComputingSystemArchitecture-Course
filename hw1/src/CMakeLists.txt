# CMakeList.txt : CMake project for СomputingSystemArchitecture-Course, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CMakeTarget "main.c" "transport.h" "transport.c" "train.c" "train.h" "plane.c" "plane.h" "ship.c" "ship.h" "container.h" "container.c" "input_helper.h" "input_helper.c")

# TODO: Add tests and install targets if needed.
