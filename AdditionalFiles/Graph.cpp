#include "Graph.h"
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph() {
	this->vertices = 0;
}

Graph::Graph(int V = 0)
{
	this->vertices = V;
	adjacencyList = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	if (v < vertices && w < vertices) {
		adjacencyList[v].push_back(w);
		//adjacencyList[w].push_back(v); only for undirected graph
		//where reverse also allowed
	}
}

void Graph::breadthFirstUtilityFunction(list <int>& queue, bool* visited) {
    list <int> ::iterator i;
    while (!queue.empty()) {
        int source = queue.front();
        std::cout << source << " ";
        visited[source] = true;
        queue.pop_front();

        for (i = adjacencyList[source].begin(); 
             i != adjacencyList[source].end();
             ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        breadthFirstUtilityFunction(queue, visited);
    }
}

void Graph::breadthFirstTraversal(int source)
{
    bool* visited = new bool[this->vertices];
    for (int i = 0; i < this->vertices; i++) visited[i] = false;

    list <int> queue;
    visited[source] = true;
    queue.push_back(source);

    breadthFirstUtilityFunction(queue, visited);
    delete[] visited;
}

void Graph::breadthFirstTraversalIterative(int source) {
    vector < bool > visited(this->vertices, false);

    list < int > queue;
    visited[source] = true;
    queue.push_back(source);

    // Get all adjacent vertices using iterator for list
    list < int > ::iterator i;
    while (!queue.empty()) {
        source = queue.front();
        cout << source << " ";
        queue.pop_front();

        for (i = adjacencyList[source].begin(); i != adjacencyList[source].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::depthFirstUtilityFunction(std::deque<int>& _stack, std::vector<bool>& _visited) {

    auto currentStackFront = _stack.front();
    _stack.pop_front();

    if (!_visited[currentStackFront]) {
        std::cout << currentStackFront << " ";
        _visited[currentStackFront] = true;
    }

    if (adjacencyList[currentStackFront].empty()) return;

    for (auto i = adjacencyList[currentStackFront].begin(); i != adjacencyList[currentStackFront].end(); ++i) {
        auto iValue = *i;
        _stack.push_front(iValue);     //insertng midway might be more efficient depending on algo        
    }

    while (!_stack.empty())
    {
        depthFirstUtilityFunction(_stack, _visited);
        std::sort(_stack.begin(), _stack.end());
    }

 /*
    auto currentStackFront = _stack.front();
    _stack.pop_front();
    depthFirstUtilityFunction(currentStackFront, _stack, _visited);

 depthFirstUtilityFunction(source, _stack, _visited);
    auto currentStackFront = _stack.front();
    if (currentStackFront <= source) {
        _stack.pop_front();
        depthFirstUtilityFunction(currentStackFront, _stack, _visited);
    }*/

}

void Graph::depthFirstTraversal(int source) {
    // write code here

    //start at source
    //get the list of connected nodes/edges
    //process the first listed node  - > add to queue for later processing 
    //process that nodes/list, it's first listed 

    vector < bool > visited(this->vertices, false);
    std::deque<int> stack{ source };
    depthFirstUtilityFunction(stack, visited);

    cout << "\n";
}

