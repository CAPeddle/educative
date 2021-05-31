// Dynamic_Palindromic.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.educative.io/courses/algorithms-coding-interviews-cpp/B6vRZowOZOk
/* 
Problem Statement #

Given a string, find the length of its Longest Palindromic Subsequence.In a palindromic subsequence, elements read the same backwardand forward.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements
*/

#include <iostream>

int LPSLengthRec(std::string st, int startIndex, int endIndex) {

  if (startIndex > endIndex)
    return 0;

  // every sequence with one element is a palindrome of length 1
  if (startIndex == endIndex)
    return 1;

  // case 1: elements at the beginning and the end are the same
  if (st[startIndex] == st[endIndex])
    return 2 + LPSLengthRec(st, startIndex + 1, endIndex - 1);

  // case 2: skip one element either from the beginning or the end
  int c1 = LPSLengthRec(st, startIndex + 1, endIndex);
  int c2 = LPSLengthRec(st, startIndex, endIndex - 1);
  return std::max(c1, c2);
}

int LPSLength(std::string st) {
  return LPSLengthRec(st, 0, st.length() - 1);
}


int main()
{
  std::string st = "abdbca";
  LPSLength(st);
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
