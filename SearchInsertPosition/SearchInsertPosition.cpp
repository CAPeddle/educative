// SearchInsertPosition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AuxiliaryFunctions.h"

#include <iostream>

int insertPosition(int arr[], int arrSize, int s) {
 
    int start = 0;
    int end = arrSize - 1;
    int mid = 0;

    if (s > arr[arrSize-1]) return arrSize;
    if (s < arr[0]) return 0;

    while (start <= end) {
        mid = (end + start) / 2;

        if (arr[mid] < s)
            start = mid + 1;
        else if (arr[mid] > s)
            end = mid - 1;
        else
            return mid;
    }

    return mid;
}

int main()
{
                //0 1 2 3 4 5
    int arr[] = { 2,4,7,9 };
    int s = 20;
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << insertPosition(arr, arrSize, s) << "\n";
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
