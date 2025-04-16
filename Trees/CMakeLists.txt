# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project(Trees)

# Include sub-projects.
add_subdirectory ("Diameter")
add_subdirectory ("Serialize")
