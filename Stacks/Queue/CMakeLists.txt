# CMakeList.txt : CMake project for MyQueue, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(MyQueue)

# Create library from source files
add_library(MyQueueLib 
    "MyQueue.cpp"
    "MyQueue.h"
)

# Add source to this project's executable.
add_executable (MyQueue "main.cpp")
target_link_libraries(MyQueue PRIVATE MyQueueLib)

# Add the test subdirectory
add_subdirectory(test)
