// Greedy_Policemen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


int policeThief(char policeThiefArray[], int n, int k) {
	int result = 0;
	std::vector<int> thieves;
	std::vector<int> police;

	// store indices in the respective vector
	for (int i = 0; i < n; i++) {
		if (policeThiefArray[i] == 'P')
			police.push_back(i);
		else if (policeThiefArray[i] == 'T')
			thieves.push_back(i);
	}

	int trackThieves = 0, trackPolice = 0;
	while (trackThieves < thieves.size() && trackPolice < police.size()) {
		if (abs(thieves[trackThieves] - police[trackPolice]) <= k) {
			result++;
			trackThieves++;
			trackPolice++;
		}

		// increment the minimum index 
		else if (thieves[trackThieves] < police[trackPolice])
			trackThieves++;
		else
			trackPolice++;
	}

	return result;
}

int main()
{
    {
        char policeThiefArray[] = { 'P', 'T', 'T', 'P', 'T' },
        int n = sizeof(policeThiefArray) / sizeof(policeThiefArray[0]);
        int k = 1;
        std::cout << policeThief(policeThiefArray, n, k) << "\n";
    }

    {
        char policeThiefArray[] = { 'P', 'T', 'T', 'P', 'T' },
        int n = sizeof(policeThiefArray) / sizeof(policeThiefArray[0]);
        int k = 1;
        std::cout << policeThief(policeThiefArray, n, k) << "\n";
    }
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
