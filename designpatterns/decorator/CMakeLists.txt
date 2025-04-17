cmake_minimum_required (VERSION 3.14)

# Define the project name
project(Decorator)

# Create library from source files
add_library(DecoratorLib 
    "Decorator.cpp"
    "Decorator.hpp"
)

# Add source to this project's executable.
add_executable (Decorator "main.cpp")
target_link_libraries(Decorator PRIVATE DecoratorLib)

# Add the test subdirectory
# add_subdirectory(test)