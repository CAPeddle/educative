cmake_minimum_required(VERSION 3.14)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(LinkedListTest LinkedListTest.cpp)
target_link_libraries(LinkedListTest gtest_main)
add_test(NAME LinkedListTest COMMAND LinkedListTest)