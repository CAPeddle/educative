#include <iostream>
#include <string>
#include <vector>
#include "Palindrome.h"

int main()
{
    std::string st = "tact coa";
    std::cout << "Is " << st << " a palindrome permutation? " << (Palindrome::PermutePalindrome(st) ? "true" : "false") << std::endl;

    return 0;
}


