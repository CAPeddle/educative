#pragma once

#include <iostream>

class DisjointSets {
private:
    int* parent, * rank;
    int n;

public:
    DisjointSets(int n);
    int find(int u);
    void merge(int x, int y);
};
