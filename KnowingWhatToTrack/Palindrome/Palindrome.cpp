#include "Palindrome.h"

bool Palindrome::PermutePalindrome(std::string st)
{

    std::unordered_map<char, int> charCount;
    for (char c : st)
    {
        charCount[c]++;
    }

    int oddCount = 0;
    for (auto it = charCount.begin(); it != charCount.end(); it++)
    {
        if (it->second % 2 != 0)
        {
            oddCount++;
        }
    }

    if (oddCount <= 1)
    {
        return true;
    }

    return false;
}
