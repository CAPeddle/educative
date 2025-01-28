// NodesOnLevel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.numberOfNodesInGivenLevel(1);
    g.numberOfNodesInGivenLevel(2);
    g.numberOfNodesInGivenLevel(3);
    g.numberOfNodesInGivenLevel(4);

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

    h.numberOfNodesInGivenLevel(1);
    h.numberOfNodesInGivenLevel(2);
    h.numberOfNodesInGivenLevel(3);
    h.numberOfNodesInGivenLevel(4);
    h.numberOfNodesInGivenLevel(5);

    cout << "\n";

    Graph i(6);
    i.addEdge(0, 1);
    i.addEdge(0, 2);
    i.addEdge(1, 3);
    i.addEdge(2, 3);
    i.addEdge(2, 4);
    i.addEdge(3, 5);
    
    i.numberOfNodesInGivenLevel(1);
    i.numberOfNodesInGivenLevel(2);
    i.numberOfNodesInGivenLevel(3);
    i.numberOfNodesInGivenLevel(4);

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
        
    j.numberOfNodesInGivenLevel(1);
    j.numberOfNodesInGivenLevel(2);
    j.numberOfNodesInGivenLevel(3);
    j.numberOfNodesInGivenLevel(4);
    j.numberOfNodesInGivenLevel(5);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
