#include <iostream>
#include <string>
#include <vector>
#include "NoOfIslands.h"

int main()
{
    std::vector<std::vector<std::string>> matrix = {
        {"x", "x", ".", ".", ".", "."},
        {"x", "x", ".", ".", ".", "."},
        {".", ".", "x", ".", ".", "."},
        {"x", ".", ".", "x", "x", "."},
        {"x", ".", "x", ".", "x", "."},
        {"x", "x", "x", ".", ".", "."}
    };

    
    std::cout << "No of islands: " << NoOfIslands::countIslands(matrix) << std::endl;

    return 0;
}


