// Dynamic_Levenshtein.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) {
  return std::min(std::min(x, y), z);
}

int minEditDist(std::string str1, std::string str2, int m, int n) {
  // Write your code here

  if (str1 == str2) return 0;

  auto longestStr = str1.length() >= str2.length() ? str1 : str2;
  auto shorterStr = str1.length() < str2.length() ? str1 : str2;

  size_t longStrIndex = 0;

  size_t changes = 0;

  while (longStrIndex != longestStr.length())
  {    
    if (longestStr.at(longStrIndex) != shorterStr.at(longStrIndex))
    {
      longestStr.erase(longStrIndex, 1);
      ++changes;
    }
    else if (longestStr.at(longStrIndex) != shorterStr.at(longStrIndex))
    {
      ++longStrIndex;
      ++changes;
    } else
    {
      ++longStrIndex;      
    }
  }

  //compare with a character out then add the differences
  return changes;
}

int main()
{
  std::string str1 = "sunday";
  std::string str2 = "saturday";
  int m = str1.length();
  int n = str2.length();

  minEditDist(str1, str2, m, n);

  str1 = "www.educative.io / explore";
  str2 = "educative.io / edpresso";

  m = str1.length();
  n = str2.length();

  minEditDist(str1, str2, m, n);

  str1 = "abcd1234";
  str2 = "efg1234h";

  m = str1.length();
  n = str2.length();

  minEditDist(str1, str2, m, n);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


int minEditDistTabulization(std::string str1, std::string str2, int m, int n) {
  // Create a table to store results of subproblems 
  //int lookupTable[m + 1][n + 1];

  int** lookupTable = new int*[m + 1];
  for (auto i = 0; i <= m; i++) {
    lookupTable[i] = new int[n + 1];
  }

  // Fill lookupTable[][] in bottom up manner 
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      // If first string is empty, only option is to 
      // insert all characters of second string 
      if (i == 0)
        lookupTable[i][j] = j; // Min. operations = j 

      // If second string is empty, only option is to 
      // remove all characters of second string 
      else if (j == 0)
        lookupTable[i][j] = i; // Min. operations = i 

      // If last characters are same, ignore last char 
      // and recur for remaining string 
      else if (str1[i - 1] == str2[j - 1])
        lookupTable[i][j] = lookupTable[i - 1][j - 1];

      // If the last character is different, consider all 
      // possibilities and find the minimum 
      else
        lookupTable[i][j] = 1 + min(lookupTable[i][j - 1], // Insert 
          lookupTable[i - 1][j], // Remove 
          lookupTable[i - 1][j - 1]); // Replace 
    }
  }

  return lookupTable[m][n];
}
