#include "Graph.h"
#include "DisjointSets.h"
#include "WeightedGraph.h"

#include <utility>


int main() {

    int V = 4, E = 5;
    WeightedGraph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    cout << "Minimum Spanning Tree of Graph 1" << endl;
    g.kruskalMST();
    cout << endl << endl;
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

    cout << "Minimum Spanning Tree of Graph 2" << endl;
    g2.kruskalMST();


    return 0;
}