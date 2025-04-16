# CMakeList.txt : CMake project for TreeDiameter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(TreeDiameter)

# Create library from source files
add_library(TreeDiameterLib 
    "BinaryTree.cpp"
    "TreeNode.cpp"
)

# Add source to this project's executable.
add_executable (TreeDiameter "main.cpp")
target_link_libraries(TreeDiameter PRIVATE TreeDiameterLib)

# Add the test subdirectory
add_subdirectory(test)
