#include "AuxiliaryFunctions.h"


void printVector(const std::vector<int>& _vector) {
    for (std::vector<char>::const_iterator i = _vector.begin(); i != _vector.end(); ++i)
        std::cout << *i << ' ';
}

int findMin(int* arr, int start, int end) {
    if (end <= 0 || start < 0)
        return -1;

    int minInd = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[minInd] > arr[i])
            minInd = i;
    }
    return minInd;
}

int findMax(int* arr, int start, int end) {
    if (end <= 0 || start < 0)
        return -1;

    int maxInd = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[maxInd] < arr[i])
            maxInd = i;
    }
    return maxInd;
}
