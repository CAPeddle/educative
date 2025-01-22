// TwoNumbersThatAddUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<unordered_set>
#include "../AdditionalFiles/QuickSort.h"
#include "../AdditionalFiles/AuxiliaryFunctions.h"


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
  return 0; // placeholder to avoid compiler error

}

std::vector<int> findSum(int arr[], int arrSize, int s) {
  // You can copy your implementation of a sorting function here
  // Out implementation of QuickSort can be used and is prepended as 
  //std::cout << "s " << s << "\n";
  quickSort(arr, 0, arrSize - 1);

  std::vector<int> elements;

  auto half = div(s, 2).quot;
  //std::cout << "half " << half << " other half " << s - half << "\n";
  printArray(arr, arrSize);
  //std::cout << "\n";

  for (int i = half; i != s; i += copysign(1, s))
  {
    auto location = binarySearch(i, arr, arrSize);
    if (location > 0) {
        //std::cout << location << " " << arr[location] << "\n";
        auto otherValue = s - i;
        //std::cout << "othervalue " << otherValue;
        elements.push_back(i);
        elements.push_back(otherValue);
    }
  }

  // Write your code here
  return elements;
}

int main()
{

    int  arr[] = { 1,21,3,14,5,60,7,6 };
    int  arrSize = sizeof(arr) / sizeof(arr[0]);
    auto value = 81;

    auto answer = findSum(arr, arrSize, value);
    arrSize = sizeof(answer) / sizeof(answer[0]);
    printVector(answer);
    std::cout << "\n\n";

    int  arr2[] = { -26, -25, -8, -1 , 12, 17 };
    arrSize = sizeof(arr2) / sizeof(arr2[0]);
    value = -33;
        
    answer = findSum(arr2, arrSize, value);
    arrSize = sizeof(answer) / sizeof(answer[0]);
    printVector(answer);
    std::cout << "\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
