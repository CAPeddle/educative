#pragma once

#include <list> 
#include <vector>
#include <deque>
using namespace std;

class Graph {
    int vertices;
    list<int>* adjacencyList;

public:
    Graph();
    Graph(int V);
    void addEdge(int v, int w);
    void breadthFirstTraversal(int source);
    void breadthFirstTraversalIterative(int source);
    void depthFirstTraversal(int source);

private:
    void breadthFirstUtilityFunction(list <int>& queue, bool* visited);
    void depthFirstUtilityFunction(std::deque<int>& _stack, std::vector<bool>& _visited);
};

