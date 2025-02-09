// https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/4576271021506560

#include "SearchInARotatedArray.h"

#include <iostream>
#include <vector>


//Solution from Educative. This is a good solution, not needing the 
//search for minimum element in the array. It always does the "binary"
//search in the correct half of the array.
int BinarySearchRotated(std::vector<int>& nums, int target) {
	int low = 0;
	int mid = 0;
	int high = nums.size() - 1;
	
	while (low <= high) {
		// Finding the mid using integer division
		mid = low + (high - low) / 2;
		// Target value is present at the middle of the numsay
		if (nums[mid] == target) return mid;
		// low to mid is sorted

		if (nums[low] <= nums[mid]) {
			if (nums[low] <= target && target < nums[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		// mid to high is sorted
		else {
			if (nums[mid] < target && target <= nums[high]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
	return -1;
}


std::vector<int>::const_iterator minBinarySearch(const std::vector<int>& nums) {
  long left = 0;
  long right = nums.size() - 1;

  while (left < right) {
    long mid = left + (right - left) / 2;

    if (nums[mid] >= nums[right]) {
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
    // return static_cast<int>(std::distance(arr.cbegin(), it));
    return BinarySearchRotated(arr, target);
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
