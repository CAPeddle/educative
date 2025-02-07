// Greedy_CoinCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../AdditionalFiles/AuxiliaryFunctions.h"

#include <iostream>
#include <vector>
int coinsAvailable[] = { 1, 5, 10, 25 };
int n = sizeof(coinsAvailable) / sizeof(coinsAvailable[0]);

void findMinCoins(int V) {
  std::cout << "The Required Coins: ";
  // write your code here
  std::vector<int> coinsUsed;

  int coinsIndex = 3;
  while (V>0 && coinsIndex >= 0)
  {
    if (V >= coinsAvailable[coinsIndex])
    {
      V -= coinsAvailable[coinsIndex];
      coinsUsed.push_back(coinsAvailable[coinsIndex]);
    } else
    {
      --coinsIndex;
    }
  }

  printContainer(coinsUsed);
}

int main()
{
    findMinCoins(19);
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
