#include "WeightedGraph.h"



#include <algorithm>
#include <iostream>
#include <ostream>

#include "DisjointSets.h"


WeightedGraph::WeightedGraph(int V, int E)
{
  this->vertices = V;
  this->edges = E;
}

void WeightedGraph::addEdge(int u, int v, int w)
{
  edgesArray.push_back({w, {u, v}});
}

int WeightedGraph::kruskalMST() {
  int weightOfMST = 0;

  // lets first sort all the edges.
  sort(edgesArray.begin(), edgesArray.end());

  DisjointSets mySetDataStructure(this->vertices);

  std::vector <std::pair <int, myPair>> ::iterator iterator;
  for (iterator = edgesArray.begin(); iterator != edgesArray.end(); iterator++) {
    int u = iterator->second.first;
    int v = iterator->second.second;

    int set_u = mySetDataStructure.find(u);
    int set_v = mySetDataStructure.find(v);

    if (set_u != set_v) {
      std::cout << u << " -- " << v << std::endl;
      weightOfMST += iterator->first;
      mySetDataStructure.merge(set_u, set_v);
    }
  }
  return weightOfMST;
}
