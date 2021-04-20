// CountElementOccurrence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AuxiliaryFunctions.h"

#include <iostream>
#include <vector>
#include <unordered_map>


int calcFreq(int arr[], int arrSize, int s) {
	// Write your code here
	int occurrences{ 0 };
	std::unordered_map<int, int> occurs;

	for (size_t i = 0; i < arrSize; i++)
	{
		if (!occurs.insert(std::pair<int, int>(arr[i], 0)).second) {
			if (occurrences == 0) ++occurrences;
			++occurrences;
		}
	}

	return occurrences;
}


int main()
{				// 0  1 2 3 4 5 6 7 8
	int arr[] = { -5,-3,0,1,3,3,3,4,5 };
	int s = 3;
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	std::cout << calcFreq(arr, arrSize, s);
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
