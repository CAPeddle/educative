#ifndef WEIGHTED_GRAPH
#define WEIGHTED_GRAPH

#include <utility>
#include <vector>

# define INF 0x3f3f3f3f 
typedef std::pair <int, int> myPair;

class WeightedGraph {
  int vertices, edges;
  std::vector <std::pair <int, myPair>> edgesArray;

public:
  WeightedGraph(int V = 0, int E = 0);
  void addEdge(int u, int v, int w);
  int kruskalMST();
	void shortestPath(int s);
};


#endif
