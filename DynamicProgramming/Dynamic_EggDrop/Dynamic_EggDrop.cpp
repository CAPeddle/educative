// Dynamic_EggDrop.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.educative.io/courses/algorithms-coding-interviews-cpp/B89EJ9L7AVn
//
/*
Problem Statement #

Given a tall skyscraper and a few eggs, write a function to figure out how many tries it would take to figure out which floor of the skyscraper that the eggs can be safely dropped from without breaking. Here are some rules,

    An egg that survives a fall can be used again. A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If an egg breaks when dropped, then it would break if dropped from a higher floor.
    If an egg survives a fall then it would survive a shorter fall.

 */
#include <iostream>
#include <algorithm>

int eggDropBrute(int eggs, int floors) {
  // If there are no eggs, then there can't be any tries
  if (eggs <= 0)
    return 0;

  // If there are no floors, then no trials needed. OR if there is 
  // one floor, one trial needed.
  if (floors == 1 || floors == 0)
    return floors;

  // We need k trials for one egg and k floors 
  if (eggs == 1)
    return floors;

  int min = INT_MAX;
  int x, res;

  // Consider all droppings from 1st floor to kth floor and 
  // return the minimum of these values plus 1. 
  for (x = 1; x <= floors; x++) {
    res = std::max(eggDropBrute(eggs - 1, x - 1), eggDropBrute(eggs, floors - x));
    if (res < min)
      min = res;
  }

  return min + 1;
}




// Find sum of binomial coefficients xCi 
// (where i varies from 1 to n). If the sum 
// becomes more than K 
int binomialCoeff(int x, int n, int k) {
  int sum = 0, term = 1;
  for (int i = 1; i <= n && sum < k; ++i) {
    term *= x - i + 1;
    term /= i;
    sum += term;
  }
  return sum;
}

// Do binary search to find minimum 
// number of trials in worst case. 
int eggDrop(int eggs, int floors) {
  // If there are no eggs, then there can't be any tries
  if (eggs <= 0)
    return 0;
  
  // If there are no floors, then no trials needed. OR if there is 
  // one floor, one trial needed.
  if (floors == 1 || floors == 0)
    return floors;

  // We need k trials for one egg and k floors 
  if (eggs == 1)
    return floors;  
  
  // Initialize low and high as 1st 
  // and last floors 
  int low = 1, high = floors;

  // Do binary search, for every mid, 
  // find sum of binomial coefficients and 
  // check if the sum is greater than k or not. 
  while (low < high) {
    int mid = (low + high) / 2;
    if (binomialCoeff(mid, eggs, floors) < floors)
      low = mid + 1;
    else
      high = mid;
  }

  return low;
}

int main()
{
  int eggs = 6;
  int floors = 15;

    std::cout << "Hello World!\n";
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
