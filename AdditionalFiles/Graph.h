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
    void printGraph();
    void printAllPaths(int source, int destination);
    Graph getTranspose();
    void breadthFirstTraversal(int source);
    void breadthFirstTraversalIterative(int source);
    void depthFirstTraversal(int source, std::vector<bool>& _visited);
    int numberOfNodesInGivenLevel(int level);
    bool isStronglyConnected();

private:
    int numberOfNodesInGivenLevelUtilityFunction(int level, int _source, std::vector<bool>& _visited);
    void breadthFirstUtilityFunction(list <int>& queue, bool* visited);
    void depthFirstUtilityFunction(std::deque<int>& _stack, std::vector<bool>& _visited);    
    void printAllPathsUtilityFunction(const int& _vertex, const int& _destination, std::deque<int> _path);
};

