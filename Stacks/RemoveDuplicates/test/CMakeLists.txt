cmake_minimum_required(VERSION 3.14)



# Now simply link against gtest or gtest_main as needed. Eg
add_executable(RemoveDuplicatesTest RemoveDuplicatesTest.cpp)

# Include the directory containing the source headers
target_include_directories(RemoveDuplicatesTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(RemoveDuplicatesTest gtest_main)
add_test(NAME RemoveDuplicatesTest COMMAND RemoveDuplicatesTest)

