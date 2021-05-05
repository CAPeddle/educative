// TransposeGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// https://www.educative.io/courses/algorithms-coding-interviews-cpp/myj0v2P4mYE
//


#include <iostream>
#include "Graph.h"

int main()
{
    Graph k(5);
    k.addEdge(0, 1);
    k.addEdge(1, 2);
    k.addEdge(2, 3);
    k.addEdge(3, 0);
    k.addEdge(2, 4);
    k.addEdge(4, 2);
    
    k.getTranspose();

    cout << "\n";

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.getTranspose();

    cout << "\n";

    Graph h(8);

    h.addEdge(0, 1);
    h.addEdge(1, 2);
    h.addEdge(1, 3);

    h.addEdge(2, 4);

    h.addEdge(4, 6);
    h.addEdge(4, 7);

    h.addEdge(3, 5);
    h.addEdge(5, 6);

    h.getTranspose();

    cout << "\n";

    Graph i(6);
    i.addEdge(0, 1);
    i.addEdge(0, 2);
    i.addEdge(1, 3);
    i.addEdge(2, 3);
    i.addEdge(2, 4);
    i.addEdge(3, 5);

    i.getTranspose();

    cout << "\n";

    Graph j(8);
    j.addEdge(0, 1);
    j.addEdge(1, 2);
    j.addEdge(1, 3);
    j.addEdge(1, 4);

    j.addEdge(2, 5);
    j.addEdge(2, 6);

    j.addEdge(3, 5);
    j.addEdge(3, 6);

    j.addEdge(4, 6);

    j.addEdge(5, 7);
    j.addEdge(6, 7);

    j.getTranspose();

}