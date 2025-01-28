// GraphProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <utility>

#include "../AdditionalFiles/WeightedGraph.h"
typedef std::pair <int, int> myPair;


int main() {

  int V = 4, E = 5;
  WeightedGraph g(V, E);

  g.addEdge(0, 1, 10);
  g.addEdge(0, 2, 6);
  g.addEdge(0, 3, 5);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);

  std::cout << "Minimum Spanning Tree of Graph 1" << std::endl;
  g.kruskalMST();
  std::cout << std::endl << std::endl;
  //////////////////

  V = 6;
  E = 15;
  WeightedGraph g2(V, E);
  g2.addEdge(0, 1, 4);
  g2.addEdge(0, 2, 4);
  g2.addEdge(1, 2, 2);
  g2.addEdge(1, 0, 4);
  g2.addEdge(2, 0, 4);
  g2.addEdge(2, 1, 2);
  g2.addEdge(2, 3, 3);
  g2.addEdge(2, 5, 2);
  g2.addEdge(2, 4, 4);
  g2.addEdge(3, 2, 3);
  g2.addEdge(3, 4, 3);
  g2.addEdge(4, 2, 4);
  g2.addEdge(4, 3, 3);
  g2.addEdge(5, 2, 2);
  g2.addEdge(5, 4, 3);

  std::cout << "Minimum Spanning Tree of Graph 2" << std::endl;
  g2.kruskalMST();


  return 0;
}