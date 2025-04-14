cmake_minimum_required (VERSION 3.14)

# Define the project name
project(Facade)

# Create library from source files
add_library(FacadeLib 
    "Facade.cpp"
    "Facade.hpp"
)

# Add source to this project's executable.
add_executable (Facade "main.cpp")
target_link_libraries(Facade PRIVATE FacadeLib)

# Add the test subdirectory
# add_subdirectory(test)