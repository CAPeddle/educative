#include <gtest/gtest.h>

#include <unordered_map>

#include "RemoveDuplicates.h"

TEST(RemoveDuplicates, TestName) {
  
  std::string test("azxxzy");
  bool result = (StackRemoveDuplicates::RemoveDuplicates(test) == "ay");
  std::cout << test << result << "palindrome\n";

  std::string test2("abbaca");
  EXPECT_EQ(StackRemoveDuplicates::RemoveDuplicates(test2), "ca");

  std::string test3("aabbcc");
  EXPECT_EQ(StackRemoveDuplicates::RemoveDuplicates(test3), "");

  std::string test4("abcde");
  EXPECT_EQ(StackRemoveDuplicates::RemoveDuplicates(test4), "abcde");

  std::string test5("a");
  EXPECT_EQ(StackRemoveDuplicates::RemoveDuplicates(test5), "a");

  std::string test6("");
  EXPECT_EQ(StackRemoveDuplicates::RemoveDuplicates(test6), "");
}
