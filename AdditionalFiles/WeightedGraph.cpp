#include "WeightedGraph.h"
#include "DisjointSets.h"
#include <algorithm>
#include <vector>
#include <queue>
#include <list>

WeightedGraph::WeightedGraph(int V, int E) {
    this->vertices = V;
    this->edges = E;
}

void WeightedGraph::addEdge(int u, int v, int w) {
    edgesArray.push_back({ w, {u, v} });
}

int WeightedGraph::kruskalMST() {
    int weightOfMST = 0;

    // lets first sort all the edges.
    std::sort(edgesArray.begin(), edgesArray.end());

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


void WeightedGraph::shortestPath(int source) {

    // Syntax for built in Priority queue
    // use the key word "greater" to use it like a min heap
    // we want smallest edges to be at the top
    std::priority_queue <myPair, std::vector <myPair>, std::greater <myPair>> myPriorityQueue;

    //array to maintain the shortest edges
    std::vector<int> distanceArray(vertices, INF);

    //push the source first because source has 0 distance with itself
    myPriorityQueue.push(std::make_pair(0, source));
    distanceArray[source] = 0;

    // now start iterating the queue.
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().second;
        myPriorityQueue.pop();

        std::list <std::pair<int, int>>::iterator i;
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            //update distance of u->v if shorter edge found
            if (distanceArray[v] > distanceArray[u] + weight) {
                distanceArray[v] = distanceArray[u] + weight;

                // priority queue acts like a min heap so each time only smallest edges at top
                myPriorityQueue.push(std::make_pair(distanceArray[v], v));
            }
        }
    }

    for (int i = 0; i < vertices; ++i)
        if (i == vertices - 1)
            std::cout << i << " --> " << distanceArray[i];
        else
            std::cout << i << " --> " << distanceArray[i] << ", ";
}