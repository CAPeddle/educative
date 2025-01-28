cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(NoOfIslandsTest 
    "NoOfIslandsTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(NoOfIslandsTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(NoOfIslandsTest gtest_main)
target_link_libraries(NoOfIslandsTest 
    PRIVATE
    gtest_main
    NoOfIslandsLib
)

# target_link_libraries(NoOfIslandsTest gtest_main)
add_test(NAME NoOfIslandsTest COMMAND NoOfIslandsTest)


