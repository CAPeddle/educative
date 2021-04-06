// SearchInARotatedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AuxiliaryFunctions.h"


int searchRotatedArray(int arr[], int left, int right, int s) {
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

    return -1;
}

int main()
{
    int arr[] = { 7, 8, 9, 0, 3, 5, 6 };
    int left = 0; // Index of the start of the array
    int right = 6; // Index of the end of the array

    int s = 7; // Element that is being searched for
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 8;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 9;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 0;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 3;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 5;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 6;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 10;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";
    s = 4;
    std::cout << " out " << searchRotatedArray(arr, left, right, s) << "\n";

    int arr2[] = { 5, 6, 7, 1, 2, 3, 4 };
    left = 0; // Index of the start of the array
    right = 6; // Index of the end of the array
    s = 0; // Element that is being searched for
    std::cout << " out " << searchRotatedArray(arr2, left, right, s) << "\n";
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
