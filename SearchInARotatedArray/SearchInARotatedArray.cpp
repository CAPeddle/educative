// https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/4576271021506560

#include "SearchInARotatedArray.h"

#include <iostream>
#include <vector>

std::vector<int>::const_iterator minBinarySearch(const std::vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return nums.cbegin() + left;
}

std::vector<int>::const_iterator binarySearch(const std::vector<int>& arr,
                                              int target) {
  auto start = arr.begin();
  auto end = arr.end() - 1;
  auto mid = start + std::distance(start, end) / 2;

  auto minElementIt = minBinarySearch(arr);

  if (target >= *minElementIt && target <= *end) {
    start = minElementIt;
  } else {
    end = minElementIt - 1;
  }


  while (start <= end) {
    mid = start + std::distance(start, end) / 2;

    if (*mid == target) {
      return mid;
    } else if (*mid < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return arr.end();
}

int SearchInARotatedArray::find(std::vector<int> arr, int target) {
  if (arr.empty()) {
    return -1;
  }

  auto it = binarySearch(arr, target);

  if (it == arr.cend()) {
    return -1;
  } else {
    return static_cast<int>(std::distance(arr.cbegin(), it));
  }
}

int SearchInARotatedArray::min(std::vector<int> arr) {
  if (arr.empty()) {
    return -1;
  }

  auto it = minBinarySearch(arr);

  if (it == arr.cend()) {
    return -1;
  } else {
    return static_cast<int>(std::distance(arr.cbegin(), it));
  }
}
