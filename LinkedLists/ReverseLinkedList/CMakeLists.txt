# CMakeList.txt : CMake project for ReverseLinkedList, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(ReverseLinkedList)

# Create library from source files
add_library(ReverseLinkedListLib 
    "LinkedList.cpp"
    "LinkedList.h"
    "LinkedListNode.h"
)

# Add source to this project's executable.
add_executable (ReverseLinkedList "main.cpp")
target_link_libraries(ReverseLinkedList PRIVATE ReverseLinkedListLib)

# Add the test subdirectory
# add_subdirectory(test)