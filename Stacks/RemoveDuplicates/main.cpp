#include <iostream>
#include <string>
#include "RemoveDuplicates.h"



int main()
{
    std::string test("azxxzy");
    bool result = (StackRemoveDuplicates::RemoveDuplicates(test) == "ay");
    std::cout << test << result << "fail\n";

}


