// SearchinSortedMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AuxiliaryFunctions.h"

#include <iostream>
#include <vector>



int search(std::vector<std::vector<int>> matrix, int numberOfRows, int numberOfColumns, int target) {
    // write your code here

    std::vector<int> column1;
    std::vector<int> rowOfInterest;

    for (int i = 0; i < numberOfRows; i++) {
        column1.push_back(matrix.at(i).at(0));
    }
    
    //Find row that Target is bigger than but less than the next row
    int row = containingIndex(target, column1);
    std::cout << "column1: ";
    printVector(column1);
    std::cout << "\ntarget:" << target << " row:" << row << "\n";
    for (int i = 0; i < numberOfColumns; i++) {rowOfInterest.push_back(matrix.at(row).at(i)); }
    printVector(rowOfInterest);
    std::cout << "\n";

    return binarySearch(target, rowOfInterest) >= 0 ? 1 : 0;
}

int main()
{
    std::vector<std::vector<int>> matrix = { {10, 11, 12, 13}, {14, 15, 16, 17}, {27, 29, 30, 31}, {32, 33, 39, 80} };

    int target = 30;    
    std::cout << search(matrix, 4, 4, target) << " " << "\n";

    target = 80;
    std::cout << search(matrix, 4, 4, target) << " " << "\n";

    /*
                            //0    1   2   3    4   5   6   7
    std::vector<int> test = { 10, 15, 20 , 25, 30, 35, 40, 45 }; 
    printVector(test);
    std::cout  << "\n" << "\n";

    target = 11;
    std::cout << target << " " << containingIndex(target, test) << "\n";
    target = 15;
    std::cout << target << " " << containingIndex(target, test) << "\n";
    target = 16;
    std::cout << target << " " << containingIndex(target, test) << "\n";
    target = 21;
    std::cout << target << " " << containingIndex(target, test) << "\n";
    target = 22;
    std::cout << target << " " << containingIndex(target, test) << "\n";

    target = 34;
    std::cout << target << " " << containingIndex(target, test) << "\n";
    target = 46;
    std::cout << target << " " << containingIndex(target, test) << "\n";


                             // 0   1   2   3 
    std::vector<int> test2 = { 10, 14, 27 , 32 };
    target = 30;
    std::cout << target << " " << containingIndex(target, test2) << "\n";
    */
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
