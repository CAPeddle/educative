// Dynamic_LongestCommonSub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>


int longestCommonSubstrLengthUtility(std::string s1, std::string s2, int start, int end)
{
  const auto s1Sub = s1.substr(start, end - start);
  const auto s2Sub = s2.substr(start, end - start);

  std::cout << s1Sub << "\n" << s2Sub << "\n--------------\n";

  if (s1Sub == s2Sub)
  {
    longestCommonSubstrLengthUtility(s1, s2, start, end + 1);
  }

  longestCommonSubstrLengthUtility(s1, s2, ++start, ++end);

  return 0;
}

int longestCommonSubstrLength(std::string s1, std::string s2) {
  // Write your code here

  if (s1.empty() || s2.empty()) return 0;
  
  longestCommonSubstrLengthUtility(s1, s2, 0, 0);

  return 1;
}

int main()
{
  std::string s1 = "www.educative.io/explore";
  std::string s2 = "educative.io/edpresso";

  std::cout << s1 << "\n" << s2 << "\n" << longestCommonSubstrLength(s1, s2);
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
