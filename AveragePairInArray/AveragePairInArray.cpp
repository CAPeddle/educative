// AveragePairInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>


std::pair<int, int> avgPair(std::vector<int> arr, int num) {

    auto left = arr.begin();
    auto right = arr.end() - 1;

    while (left < right)
    {
        double avg = (*left + *right) / 2.0;
        if (avg == num ) return std::make_pair(*left, *right);
        if (avg < num) ++left;
        if (avg > num) --right;
    }

    return std::make_pair(0, 0);
}

int main()
{
    std::vector<int> arr = { -2,3,7,8,9 };

    auto par = avgPair(arr, 5);
    std::cout << "5 :" << par.first << ":" << par.second << "\n";

    par = avgPair(arr, 2);
    std::cout << "2 :" << par.first << ":" << par.second << "\n";
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
