#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "TwoPointers.h"


int main()
{
    std::string test("kaYak");
    std::string result = (TwoPointers::IsPalindrome(test) ? "is" : "is not");
    std::cout << test << result << "palindrome\n";

    std::unordered_map<int, std::vector<int> > test_vect =
    {
        {-1, { 1, -1, 0 }},
        {10, { 3,7,1,2,8,4,5 }},
        {21, { 3,7,1,2,8,4,5 }},
        {-8, {-1,2,1,-4,5,-3}}
    };

    for (auto& vector_test : test_vect) {
        std::string result = (TwoPointers::FindSumOfThree(vector_test.second, vector_test.first) ? " is " : " is not ");
        std::cout << " 3 Sum " << result << " possible \n";
    }
}


