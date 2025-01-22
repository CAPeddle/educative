// Dynamic_Partition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AuxiliaryFunctions.h"

#include <iostream>
#include <vector>
#include <algorithm>    // std::find

bool canPartitionBruteForce(int num[], int n) {    
    auto sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += num[i];
    }
    //O(n)
    
    if (sum % 2 != 0) return false;

    auto half = sum / 2;
    std::cout << "Half " << half << "\n";

    std::vector<decltype(n)> used;
    int numIndex = n - 1;
    while ( half > 0 && numIndex >= 0)
    {
        auto num_numIndex = num[numIndex];
        if (num[numIndex] > 0 && half >= num[numIndex])
        {
            half -= num[numIndex];
            used.push_back(num[numIndex]);
            num[numIndex] = 0;
        }
        else
        {
            --numIndex;
        }
    }

    if (half > 0) return false;

    half = sum / 2;
    numIndex = n - 1;
    while (half > 0 && numIndex >= 0)
    {
        auto num_numIndex = num[numIndex];
        if (num[numIndex] > 0 && half >= num[numIndex])
        {
            half -= num[numIndex];
            used.push_back(num[numIndex]);
            num[numIndex] = 0;
        }
        else
        {
            --numIndex;
        }
    }

    if (half > 0) return false;


    return true;
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = 4; // size
    std::cout << "Can partition ";
    printArray(arr, n);
    std::cout << canPartitionBruteForce(arr, n) << "\n";

    int arr1[] = { 1,2,3,4,5,6 };
    n = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "\nCan partition ";
    printArray(arr1, n);
    std::cout << canPartitionBruteForce(arr1, n) << "\n";

    int arr2[] = { 1,2,3,4,5,6,7 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "\nCan partition ";
    printArray(arr2, n);
    std::cout << canPartitionBruteForce(arr2, n) << "\n";

    int arr3[] = { 2,3,4,6 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "\nCan partition ";
    printArray(arr3, n);
    std::cout << canPartitionBruteForce(arr3, n) << "\n";

    int set2[] = { 1, 1, 3, 4, 7 };
    n = sizeof(set2) / sizeof(set2[0]);
    std::cout << "\nCan partition ";
    printArray(set2, n);
    std::cout << canPartitionBruteForce(set2, n) << "\n";
}
