#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
class RemoveDuplicates
{
public:
    static bool IsPalindrome(std::string inputString)
    {
        if (inputString.length() == 0) return false;
        if (inputString.length() == 1) return true;

        auto startptr = inputString.begin();
        auto endptr = inputString.end() - 1;


        if (*startptr != *endptr) return false;

        while (std::distance(startptr, endptr) > 1)
        {
            startptr++;
            endptr--;

            if (*startptr != *endptr) return false;
        }

        return true;
    }

    static void print_vect(std::vector<int> nums)
    {
        for (auto current = nums.begin(); current != nums.end(); ++current) {
            std::cout << *current;
            if (current + 1 != nums.end()) std::cout << ":";
        }
        std::cout << std::endl;
    }

    static bool FindSumOfThree(std::vector<int> nums, int target)
    {
        //assume assumptions hold

        std::sort(nums.begin(), nums.end());


        //print_vect(nums);

        for (auto current = nums.begin(); current != nums.end(); ++current) {
            auto startptr = current + 1;
            auto endptr = nums.end() - 1;

            while (startptr < endptr)
            {
                //std::cout << "*startptr (" << *startptr << ") + *endptr (" << *endptr << ") + *current (" << *current  << ") = " << *startptr + *endptr + *current << "(" << target << ")\n";


                //std::cout << "*current (" << *current << ") + *startptr (" << *startptr << ") + *endptr (" << *endptr << ") = " << *startptr + *endptr + *current << "(" << target << ")\n";


                auto triple = *startptr + *endptr + *current;
                if (triple == target) return true;

                if (triple < target)
                {
                    startptr++;
                }
                else {
                    endptr--;
                }
            }
        }

        return false;
    }


};

