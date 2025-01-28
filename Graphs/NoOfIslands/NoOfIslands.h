#ifndef NOISLANDS_H
#define NOISLANDS_H

#include <iostream>
#include <unordered_map>
#include <vector>

class NoOfIslands {
 public:
     static size_t countIslands(std::vector<std::vector<std::string>> matrix);
     private:
     static void removeX(std::vector<std::vector<std::string>> &matrix, int row, int column);
};



#endif  // NOISLANDS_H