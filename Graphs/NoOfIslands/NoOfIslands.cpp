#include "NoOfIslands.h"

size_t NoOfIslands::countIslands(std::vector<std::vector<std::string>> matrix) {
  if (matrix.size() == 0) {
    return 0;
  }

  size_t NoOfIslands = 0;
  size_t columnSize = matrix[0].size();
  for (int row = 0; row < matrix.size(); ++row) {
    if (matrix[row].size() != columnSize) {
      throw std::invalid_argument("Matrix rows not of same size");
    }

    for (int column = 0; column < matrix[row].size(); ++column) {
      // You can modify elements here
      if (matrix[row][column] == "x") {
        NoOfIslands++;
        removeX(matrix, row, column);
      }
    }
  }

  return NoOfIslands;
}

void NoOfIslands::removeX(std::vector<std::vector<std::string>> &matrix,
                          int row, int column) {
  if (row < 0 || row >= matrix.size() || column < 0 ||
      column >= matrix[0].size()) {
    return;
  }
  if (matrix[row][column] == "x") {
    matrix[row][column] = ".";
    removeX(matrix, row - 1, column);
    removeX(matrix, row + 1, column);
    removeX(matrix, row, column - 1);
    removeX(matrix, row, column + 1);
  }
}
