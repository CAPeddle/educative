#pragma once
#include <iostream>
#include <vector>

using namespace std;

void printArray(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printVector(const std::vector<int>& _vector) {
    for (std::vector<int>::const_iterator i = _vector.begin(); i != _vector.end(); i++)
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

int binarySearch(int s, int arr[], int arrSize) {
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

int binarySearch(int s, std::vector<int> arr) {
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

int containingIndex(int s, std::vector<int> arr) {
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