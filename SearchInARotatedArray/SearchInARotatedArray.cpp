//https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/4576271021506560

#include "SearchInARotatedArray.h"
#include <iostream>
#include <vector>

std::vector<int>::iterator binarySearch(std::vector<int> arr, int target) {
    auto start = arr.begin();
    auto end = arr.end() - 1;
    auto mid = start + std::distance(start, end) / 2;
    
    std::cout << "start: " << std::distance(arr.begin(), start) 
              << " end: " << std::distance(arr.begin(), end) 
              << " mid: " << std::distance(arr.begin(), mid) << std::endl;

    while (start <= end) {
        mid = start + std::distance(start, end) / 2;

        if (*mid < target)
            start = mid + 1;
        else if (*mid > target)
            end = mid - 1;
        else
            return mid;
    }
    return arr.end();
}

int searchRotatedArray(int arr[], int left, int right, int s) {
    /*
    // Write your code here
    int start = 0;
    int end = right;    
    auto min = findMin(arr, left, right) ;
    auto minVal = arr[min];
    auto endVal = arr[end];

    if (minVal <= s && s <= endVal) {
        auto location = binarySearch(s, &arr[min], (end - min) + 1);
        if (location >= 0) return min + location;
    }
    else
        return binarySearch(s, arr, min);

        */
    return -1;
}

int SearchInARotatedArray::find(std::vector<int> arr, int target)
{
    return static_cast<int>(std::distance(arr.begin(), binarySearch(arr, target)));
}
