#pragma once
#include <iostream>
#include <vector>

using namespace std;

void printArray(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

inline void printVector(const std::vector<int>& _vector) {
    for (auto i = _vector.begin(); i != _vector.end(); i++)
        std::cout << *i << ' ';
}

inline int findMin(int* arr, int start, int end) {
    if (end <= 0 || start < 0)
        return -1;

    int minInd = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[minInd] > arr[i])
            minInd = i;
    }
    return minInd;
}


inline int binarySearch(int s, int arr[], int arrSize) {
    int start = 0;
    int end = arrSize - 1;
    int mid;

    while (start <= end) {
        mid = (end + start) / 2;
        if (arr[mid] < s)
            start = mid + 1;
        else if (arr[mid] > s)
            end = mid - 1;
        else
            return mid;
    }
    return -2; // placeholder to avoid compiler error
}

inline int binarySearch(int s, std::vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end) {
        mid = (end + start) / 2;
        if (arr[mid] < s)
            start = mid + 1;
        else if (arr[mid] > s)
            end = mid - 1;
        else
            return mid;
    }
    return -2; // placeholder to avoid compiler error
}

inline int containingIndex(int s, std::vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = (end + start) / 2;;

    if (arr[mid] == s) return mid;

    if (arr[mid] < s) { 
        start = mid; 
    }

    while (start < end) {
        if (arr[start] <= s && arr[start + 1] > s) return start;

        ++start;

    }
    return start; // placeholder to avoid compiler error
}

inline int findMax(int* arr, int start, int end) {
    if (end <= 0 || start < 0)
        return -1;

    int maxInd = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[maxInd] < arr[i])
            maxInd = i;
    }
    return maxInd;
}