#pragma once

#include <iostream>
using namespace std;

class DisjointSets {
private:
  int* parent, * rank;
  int n;

public:
  DisjointSets(int n);
  int find(int u) const;
  void merge(int x, int y) const;
};

