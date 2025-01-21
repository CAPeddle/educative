#include <iostream>
#include <string>
#include "RemoveDuplicates.h"



int main()
{
    std::string test("kaYak");
    std::string result = (RemoveDuplicates::IsPalindrome(test) ? "is" : "is not");
    std::cout << test << result << "palindrome\n";

}


