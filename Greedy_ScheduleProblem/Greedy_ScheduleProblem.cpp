// Greedy_ScheduleProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

bool sortbysec(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.second < b.second;
}

void maxActivities(int start[], int finish[], int n) {
  std::vector<std::pair <int, int> > zipped; //zipping start and finish arrays together
  for (int i = 0; i < n; i++)
    zipped.push_back(std::make_pair(start[i], finish[i]));

  std::sort(zipped.begin(), zipped.end(), sortbysec);
  int index, j;

  std::cout << "Following activities are selected: ";

  // select first activity
  index = 0;
  std::cout << index << " ";

  for (j = 1; j < n; j++) {
    if (zipped[j].first >= zipped[index].second) {
      std::cout << j << " ";
      index = j;
    }
  }
}

int main() {
  int start[] = { 0, 3, 3, 2, 4, 3, 8, 10 };
  int finish[] = { 3, 4, 5, 7, 8, 11, 12, 13 };
  int n = sizeof(start) / sizeof(start[0]);
  maxActivities(start, finish, n);
  return 0;
}