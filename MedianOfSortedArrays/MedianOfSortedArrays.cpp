// MedianOfSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "AuxiliaryFunctions.h"

double getMedian(int array1[], int array2[], int sizeOfArray1, int sizeOfArray2) {
    // Write your code here

    std::vector<int> merged;

    int largestArraySize = std::max(sizeOfArray1, sizeOfArray2);
    size_t finalArraySize = 0;
    finalArraySize += sizeOfArray1;
    finalArraySize += sizeOfArray2;
    auto midPoint = div (finalArraySize , 2);

    size_t arr1 = 0;
    size_t arr2 = 0;

    do
    {
        if (arr1 < sizeOfArray1 && arr2 < sizeOfArray2) {
            if (array1[arr1] < array2[arr2]) {
                merged.push_back(array1[arr1++]);                
            }
            else
            {
                merged.push_back(array2[arr2++]);
            }
        }
        else if (arr1 < sizeOfArray1) {
            merged.push_back(array1[arr1++]);
        }
        else if (arr2 < sizeOfArray2) {
            merged.push_back(array2[arr2++]);
        }

        //if (merged.size() > static_cast<unsigned long long>(midPoint.quot) + 1) break;
    } while (arr1 < sizeOfArray1 || arr2 < sizeOfArray2);

    printVector(merged);

    if (midPoint.rem > 0) {
        return merged.at(midPoint.quot);
    }
    else
    {
        auto returnValue = (merged.at(midPoint.quot - 1 ) + merged.at(midPoint.quot)) / 2;
        return returnValue;
    }

    return -1;
}


int main()
{

    int A[] = { 100 };
    int B[] = { 1, 5, 8, 10, 20 };

    std::cout << "  Median:" << getMedian(A, B, 1, 5) << "\n";


    int C[] = { 2, 6, 100 };
    int D[] = { 1, 5, 8, 10, 20, 30 };

    std::cout << "  Median:" << getMedian(C, D, 3, 6) << "\n";
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
