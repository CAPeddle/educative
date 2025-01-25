cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(RateLimiterTest 
    "RateLimiterTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(RateLimiterTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(RateLimiterTest gtest_main)
target_link_libraries(RateLimiterTest 
    PRIVATE
    gtest_main
    RateLimiterLib
)

# target_link_libraries(RateLimiterTest gtest_main)
add_test(NAME RateLimiterTest COMMAND RateLimiterTest)


