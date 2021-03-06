#pragma once

#include <list> 
#include <vector>
#include <deque>
#include <stack>

using namespace std;

class Graph {
    bool directed{ true };
    int vertices;
    list<int>* adjacencyList;

public:
    Graph();
    Graph(const Graph& g);
    Graph(int V, bool _directed=true);
    void addEdge(int v, int w);
    void printGraph();
    void printAllPaths(int source, int destination);
    Graph getTranspose();
    void breadthFirstTraversal(int source);
    void breadthFirstTraversalIterative(int source);
    void depthFirstTraversal(int source, std::vector<bool>& _visited);
    int numberOfNodesInGivenLevel(int level);
    bool isConnected();
    bool isStronglyConnected();
    void printConnectedComponents();
    bool willCauseSeparateComponents(int source, int destination);
    bool isBipartite(int source) const;
    void topologicalSort();
    void greedyColoring();

  private:
    int numberOfNodesInGivenLevelUtilityFunction(int level, int _source, std::vector<bool>& _visited) const;
    void breadthFirstUtilityFunction(list <int>& queue, bool* visited);
    void depthFirstUtilityFunction(std::deque<int>& _stack, std::vector<bool>& _visited);    
    void printAllPathsUtilityFunction(const int& _vertex, const int& _destination, std::deque<int> _path);
    bool isBipartiteUtilityFunction(int v, vector<bool>& visited, vector<int>& color) const;
    void topologicalSortUtility(int v, vector<bool>& _visited, std::stack<int>& myStack);
    void removeEdge(int v, int w);
};

