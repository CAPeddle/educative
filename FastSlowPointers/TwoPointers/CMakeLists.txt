# CMakeList.txt : CMake project for TwoPointers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Add source to this project's executable.
add_executable (TwoPointers "TwoPointers.cpp" "TwoPointers.h")

# Add the test subdirectory
add_subdirectory(tests)

# TODO: Add tests and install targets if needed.
