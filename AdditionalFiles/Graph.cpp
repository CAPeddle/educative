#include "Graph.h"
#include "AuxiliaryFunctions.h"

#include <iostream>
#include <queue>

Graph::Graph() {
	this->vertices = 0;
    adjacencyList = new list<int>[0];
}

Graph::Graph(const Graph& g)
{
    directed = g.directed;
    vertices = g.vertices;
    adjacencyList = new list<int>[g.vertices];

    for (int v = 0; v < g.vertices; ++v) {
        for (auto i = g.adjacencyList[v].begin(); i != g.adjacencyList[v].end(); ++i) {
            auto iValue = *i;
            adjacencyList[v].push_back(iValue);
        }
    }
}

Graph::Graph(int V = 0, bool _directed):
    vertices(V), directed(_directed)
{
	adjacencyList = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	if (v < vertices && w < vertices) {
		adjacencyList[v].push_back(w);
        if (!directed) 
            adjacencyList[w].push_back(v); 
		//where reverse also allowed
	}
}

void Graph::removeEdge(int v, int w) {
    if (v < vertices && w < vertices) {

        auto findVertex = adjacencyList[v].begin();
        findVertex = std::find(std::begin(adjacencyList[v]), std::end(adjacencyList[v]), w);
        if (findVertex != adjacencyList[v].end()) adjacencyList[v].erase(findVertex);


        if (!directed) {
            findVertex = adjacencyList[w].begin();
            findVertex = std::find(std::begin(adjacencyList[w]), std::end(adjacencyList[w]), v);
            if (findVertex != adjacencyList[w].end()) adjacencyList[w].erase(findVertex);
        }
    }
}

void Graph::printGraph() {
    for (int v = 0; v < vertices; v++) {
        cout << v << "-->";
        list < int > ::iterator i;
        for (i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
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

    cout << "\n";
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
    cout << "\n";
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
        if (!_visited[iValue]) _stack.push_front(iValue);     //insertng midway might be more efficient depending on algo        
    }

    while (!_stack.empty())
    {
        depthFirstUtilityFunction(_stack, _visited);
        std::sort(_stack.begin(), _stack.end());
    }
}

void Graph::depthFirstTraversal(int source, std::vector<bool>& _visited) {
  
    /*
    _visited.resize(this->vertices);
    std::fill(_visited.begin(), _visited.end(), false);

    std::deque<int> stack{ source };
    depthFirstUtilityFunction(stack, _visited);*/

    _visited[source] = true;

  for (auto i = adjacencyList[source].begin(); i != adjacencyList[source].end(); ++i) {
      if (!_visited[*i]) {
        depthFirstTraversal(*i, _visited);
      }
    }
}

int Graph::numberOfNodesInGivenLevelUtilityFunction(int level, int _source, std::vector<bool>& _visited) const
{
    int levelCount{ 0 };
    
    if (level == 1) {
        return 1;
    }
    --level;

    for (auto i = adjacencyList[_source].begin(); i != adjacencyList[_source].end(); ++i) {
        auto targetNode = *i;
        if (!_visited[*i]) {
            _visited[*i] = true;            
            levelCount += numberOfNodesInGivenLevelUtilityFunction(level, *i, _visited);            
        }
    }

    return levelCount;
}

bool Graph::willCauseSeparateComponents(int source, int destination) {

    Graph changed(*this);

    if (!changed.isConnected()) return true;

    changed.removeEdge(source, destination);
  
    return (!changed.isConnected());
}

int Graph::numberOfNodesInGivenLevel(int level) {
    int count = 0;
    vector < bool > visited(this->vertices, false);
    // write code here	

    //hop down stack to get one level onwards, recursive will work will for this
    std::cout << numberOfNodesInGivenLevelUtilityFunction(level, 0, visited) << "\n";
    return count;
}

Graph Graph::getTranspose() {
    // write your code here
    auto temp = Graph(this->vertices, true) ;

    for (int v = 0; v < vertices; v++) {
        list < int > ::iterator i;
        for (i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i) {
            temp.addEdge(*i, v);
        }
    }

    return temp;
}

void Graph::printAllPathsUtilityFunction(const int& _vertex, const int& _destination, std::deque<int> _path) {

    _path.push_back(_vertex);

    if (_vertex == _destination)
    {
        printContainer(_path);
        std::cout << "\n";
        return;
    }

    if (adjacencyList[_vertex].empty()) {
        return;
    }

    for (auto i = adjacencyList[_vertex].begin(); i != adjacencyList[_vertex].end(); ++i) {
        auto iValue = *i;
        printAllPathsUtilityFunction(iValue, _destination, _path);
    }
}

void Graph::printAllPaths(int source, int destination) {    

    std::deque<int> path;
    printAllPathsUtilityFunction(source, destination, path);

    cout << "\n";
}

bool Graph::isConnected() {

    std::vector<bool> visited;
    visited.resize(this->vertices);
    std::fill(visited.begin(), visited.end(), false);

    depthFirstTraversal(0, visited);

    auto findFalse = visited.begin();
    findFalse = std::find(std::begin(visited), std::end(visited), false);

    if (findFalse != visited.end()) return false;

    return true;
}

bool Graph::isStronglyConnected() {
    //write your code here

    int start = this->vertices / 2;

    std::vector<bool> visited;    
    visited.resize(this->vertices);
    std::fill(visited.begin(), visited.end(), false);

    depthFirstTraversal(start, visited);

    auto findFalse = visited.begin();
    findFalse = std::find(std::begin(visited), std::end(visited), false);

    if (findFalse != visited.end()) return false;

    auto k = this->getTranspose();

    k.depthFirstTraversal(start, visited);
    findFalse = std::find(std::begin(visited), std::end(visited), false);
   
    if (findFalse != visited.end()) return false;

    return true;
}

void Graph::printConnectedComponents() {
    //write your code here

    std::vector<bool> visited;
    visited.resize(this->vertices);
    std::fill(visited.begin(), visited.end(), false);
 
    auto findFalse = visited.begin();
    while (findFalse != visited.end()) {
        int index = findFalse - visited.begin();
        depthFirstTraversal(index, visited);

        findFalse = std::find(std::begin(visited), std::end(visited), false);
    }   
}

bool Graph::isBipartiteUtilityFunction(int v, vector<bool>& visited, vector<int>& color) const
{
  for (auto i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i) {
    if (visited[*i] == false) {
      visited[*i] = true;

      color[*i] = !color[v]; // give different color to adjacent node

      if (this->isBipartiteUtilityFunction(*i, visited, color) == false) // recursion
        return false;
    }
    else if (color[*i] == color[v]) // if same color of adjacent node
                                      // then graph is not bipartite
      return false;
  }
  return true;
}

bool Graph::isBipartite(int source) const
{
  vector<bool> visited(this->vertices);
  vector<int> color(this->vertices);

  visited[source] = true;
  color[source] = 0;

  if (this->isBipartiteUtilityFunction(source, visited, color)) {
    return true;
  }
  return false;
}

void Graph::topologicalSortUtility(int v, vector<bool>& _visited, std::stack<int>& myStack) {
    _visited[v] = true;
    std::list<int>::iterator i;
    for (i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i)
        if (!_visited[*i])
            topologicalSortUtility(*i, _visited, myStack);

    myStack.push(v);
}

void Graph::topologicalSort() {
    std::vector<bool> visited(this->vertices, false);

    std::stack<int> myStack;
    for (int i = 0; i < this->vertices; i++)
        if (visited[i] == false)
            topologicalSortUtility(i, visited, myStack);

    while (myStack.empty() == false) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
}

void Graph::greedyColoring() {
    int* result = new int[this->vertices];

    // Assign the first color to first vertex 
    result[0] = 0;

    // Initialize remaining V-1 vertices as unassigned 
    for (int u = 1; u < this->vertices; u++)
        result[u] = -1; // no color is assigned to u 

    bool* available = new bool[this->vertices];
    for (int color = 0; color < this->vertices; color++)
        available[color] = false;

    // Assign colors to remaining V-1 vertices 
    for (int u = 1; u < this->vertices; u++) {

        list < int > ::iterator i;
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        // Find the first available color 
        int color;
        for (color = 0; color < this->vertices; color++)
            if (available[color] == false)
                break;

        result[u] = color; // Assign the found color 

        // Reset the values  
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }

    for (int u = 0; u < this->vertices; u++)
        cout << "Vertex " << u << " ---> Color " <<
        result[u] << endl;

    delete[] result;
    delete[] available;
}