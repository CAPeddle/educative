cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(RemoveDuplicatesTest 
    "RemoveDuplicatesTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(RemoveDuplicatesTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(RemoveDuplicatesTest gtest_main)
target_link_libraries(RemoveDuplicatesTest 
    PRIVATE
    gtest_main
    RemoveDuplicatesLib
)

# target_link_libraries(RemoveDuplicatesTest gtest_main)
add_test(NAME RemoveDuplicatesTest COMMAND RemoveDuplicatesTest)


