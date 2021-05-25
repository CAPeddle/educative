// D_D_ClosestNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.educative.io/courses/algorithms-coding-interviews-cpp/m25Kl6J1w8r

#include <iostream>

int min2(int a, int b) {
  return a < b ? a : b;
}

int binarySearch(int s, int arr[], int arrSize) {
  int start = 0;
  int end = arrSize - 1;
  int mid;

  while (start <= end) {
    mid = (end + start) / 2;
    if (arr[mid] < s)
      start = mid + 1;
    else if (arr[mid] > s)
      end = mid - 1;
    else
      return mid;
  }
  return -2; // placeholder to avoid compiler error
}


int closestNumber(int arrSize, int target, int arr[]) {

  // mid of left and mid of right

  int start = 0;
  int end = arrSize - 1;

  while (start <= end)
  {
    int mid = (end + start) / 2;

    const auto valueLeftOfMid = std::abs(arr[mid - 1] - target);
    const auto valueAtMid = std::abs(arr[mid] - target);
    const auto valueRightOfMid = std::abs(arr[mid+1] - target);

    if (valueLeftOfMid > valueAtMid && valueRightOfMid > valueAtMid) return arr[mid];
    if (valueLeftOfMid > valueAtMid)
    {
      start = mid;
    } else if (valueLeftOfMid < valueAtMid)
    {
      end = mid;
    }
    if (valueRightOfMid > valueAtMid)
    {
      end = mid;
    }
    else if (valueRightOfMid < valueAtMid)
    {
      start = mid;
    }
    
  }

	return -1;
}

int main()
{

    int arr[] = { -9,-4,-2,0,1,3,4,10 };
    int N = sizeof(arr) / sizeof(arr[0]);
    
    int target = 5;
  //5 14   9   7  5  4  2  1  5        
  //  -9, -4, -2, 0, 1, 3, 4, 10

  //-5  4   1   3  5  6  
  //   -9, -4, -2, 0, 1, 3, 4, 10
    std::cout << closestNumber(N,target,arr) << "Hello World!\n";

    int arr2[] = { -31, -19, -11, -3, 51, 55, 67, 69 };
    closestNumber(8, -16, arr2);

}

