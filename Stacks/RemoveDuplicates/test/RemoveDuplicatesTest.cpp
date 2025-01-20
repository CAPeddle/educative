#include <gtest/gtest.h>

#include <unordered_map>

#include "RemoveDuplicates.h"

TEST(RemoveDuplicates, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  std::vector<std::vector<int>> numsLists = {

      {2, 3, 4, 1, 7, 9}, {1, -1, 0}, {2, 4, 2, 7, 6, 3, 1}};
  std::vector<int> testList = {7, 20, -1, 8};

  EXPECT_EQ(RemoveDuplicates::FindSumOfThree(std::vector<int>({1, -1, 0}), -1),
            false);
  EXPECT_EQ(
      RemoveDuplicates::FindSumOfThree(std::vector<int>({3, 7, 1, 2, 8, 4, 5}), 10),
      true);
  EXPECT_EQ(
      RemoveDuplicates::FindSumOfThree(std::vector<int>({-1, 2, 1, -4, 5, -3}), -8),
      true);

  EXPECT_EQ(
      RemoveDuplicates::FindSumOfThree(std::vector<int>({-1, 2, 1, -4, 5, -3}), 7),
      true);

  EXPECT_EQ(
      RemoveDuplicates::FindSumOfThree(std::vector<int>({3, 7, 1, 2, 8, 4, 5}), 21),
      false);
}
