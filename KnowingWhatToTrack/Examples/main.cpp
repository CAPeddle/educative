#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Given an integer array nums and an integer k, return TRUE if there are two
// distinct indexes i and j in the array such that nums[i] ==== nums[j] and
// abs(i - j) ≤≤ k.

// Sliding Window + HashSet
//  Time: O(n)
//  Space: O(k)
bool containsNearbyDuplicateSlidingWindow(std::vector<int>& nums, int k) {
  std::unordered_set<int> window;
  for (int i = 0; i < nums.size(); i++) {
    if (i > k) window.erase(nums[i - k - 1]);
    if (!window.insert(nums[i]).second) return true;
  }
  return false;
}

// HashMap with Last Position
// Time: O(n)
// Space: O(n)
bool containsNearbyDuplicateHashmap(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> lastSeen;
  for (int i = 0; i < nums.size(); i++) {
    if (lastSeen.count(nums[i]) && i - lastSeen[nums[i]] <= k) {
      return true;
    }
    lastSeen[nums[i]] = i;
  }
  return false;
}

int main() {
  std::vector<int> nums = {1, 2, 3, 7, 1, 4};

  std::cout << containsNearbyDuplicateSlidingWindow(nums, 3) << std::endl;

  return 0;
}
