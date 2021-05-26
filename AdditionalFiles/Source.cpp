

#include "AuxiliaryFunctions.h"
#include "MergeSort.h"

int main()
{
  int arr[] = { 5, 4, 1, 0, 5, 95, 4, -100, 200, 0 };
  int arrSize = 10;
  MergeSort::mergeSort(arr, 0, arrSize - 1);
  printArray(arr, arrSize);
}
