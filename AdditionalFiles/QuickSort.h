#pragma once
#include <iostream>
using namespace std;

int choosePivot(int left, int right);
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);


int choosePivot(int left, int right) {
    // Pick 3 random numbers within the range of the array
    int i1 = left + (rand() % (right - left + 1));
    int i2 = left + (rand() % (right - left + 1));
    int i3 = left + (rand() % (right - left + 1));

    // Return their median
    return max(min(i1, i2), min(max(i1, i2), i3));
}

int partition(char arr[], int left, int right) {
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

int partition(int arr[], int left, int right) {
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


void quickSort(char arr[], int left, int right) {
    if (left < right) {
        // pi is where the pivot is at
        int pi = partition(arr, left, right);

        // Separately sort elements before and after partition 
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        // pi is where the pivot is at
        int pi = partition(arr, left, right);

        // Separately sort elements before and after partition 
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
