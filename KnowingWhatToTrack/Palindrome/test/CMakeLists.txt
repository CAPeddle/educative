cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(PalindromeTest 
    "PalindromeTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(PalindromeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(PalindromeTest gtest_main)
target_link_libraries(PalindromeTest 
    PRIVATE
    gtest_main
    PalindromeLib
)

# target_link_libraries(PalindromeTest gtest_main)
add_test(NAME PalindromeTest COMMAND PalindromeTest)


