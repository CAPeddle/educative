# CMakeList.txt : CMake project for EduLinkedListCycle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(EduLinkedListCycle)

# Add source to this project's executable.
add_executable (EduLinkedListCycle  "EduLinkedListCycle.cpp" "EduLinkedListCycle.cpp" "EduLinkedListNode.cpp" )

# Add the test subdirectory
# add_subdirectory(tests)

# TODO: Add tests and install targets if needed.
