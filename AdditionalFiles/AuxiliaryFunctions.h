#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

#include <iostream>
#include <vector>

using namespace std;

inline int choosePivot(int left, int right) {
  // Pick 3 random numbers within the range of the array
  int i1 = left + (rand() % (right - left + 1));
  int i2 = left + (rand() % (right - left + 1));
  int i3 = left + (rand() % (right - left + 1));

  // Return their median
  return max(min(i1, i2), min(max(i1, i2), i3));
}

inline int partition(int arr[], int left, int right) {
  int pivotInd = choosePivot(left, right); // Index of pivot
  swap(arr[right], arr[pivotInd]); // put the pivot at the end
  int pivot = arr[right]; // Pivot 
  int i = (left - 1); // All the elements less than or equal to the
  // pivot go before or at i

  for (int j = left; j <= right - 1; j++) {
    if (arr[j] <= pivot) {
      i++; // increment the index 
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]); // Putting the pivot back in place
  return (i + 1);
}

inline void quickSort(int arr[], int left, int right) {
  if (left < right) {
    // pi is where the pivot is at
    int pi = partition(arr, left, right);

    // Separately sort elements before and after partition 
    quickSort(arr, left, pi - 1);
    quickSort(arr, pi + 1, right);
  }
}

//int arr[] = { -5,-3,0,1,3,3,3,4,5 };
//int s = 3;
//int arrSize = sizeof(arr) / sizeof(arr[0]);
//
//void printArray(int* arr, int arrSize) {
//    for (int i = 0; i < arrSize; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//}

template<typename T>
void printContainer(T theContainer)
{
    for (auto it = theContainer.begin(); it != theContainer.end(); ++it) {
        if ((it + 1) != theContainer.end())
            std::cout << *it << ':';
        else
            std::cout << *it;
    }
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

#endif