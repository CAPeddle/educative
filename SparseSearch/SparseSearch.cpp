// SparseSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AuxiliaryFunctions.h"
#include <iostream>

int searchForString(string array[], int size, string target) {
  // Write your code here

  int start = 0;
  int end = size - 1;
  int mid;

  //https://www.cplusplus.com/reference/string/string/compare/

  while (start <= end) {
    mid = (end + start) / 2;
    std::string valueAtMid = array[mid];
    auto comparison = valueAtMid.compare(target);
    auto otherComparison = target.compare(valueAtMid);


    if (valueAtMid < target)
      start = mid + 1;
    else if (valueAtMid > target)
      end = mid - 1;
    else
      return mid;
  }
  
  return -1;
}

int main()
{
  string array[] = { "", "educative", "", "", "",  "hello", "", "learning", "world", "", "", "" };

  const int arrSize = sizeof(array) / sizeof(array[0]);

  const auto target = "educative";

  std::cout << searchForString(array,arrSize,target) << "\n";
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
