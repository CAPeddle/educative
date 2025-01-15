# CMakeList.txt : CMake project for LinkedListCycle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(LinkedListCycle)

# Add source to this project's executable.
add_executable (LinkedListCycle  "LinkedListCycle.cpp" "LinkedListCycle.cpp" "LinkedListNode.cpp" )

# Add the test subdirectory
# add_subdirectory(tests)

# TODO: Add tests and install targets if needed.
