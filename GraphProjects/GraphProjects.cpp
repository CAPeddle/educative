// GraphProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

int main()
{
    Graph k(7);
    k.addEdge(0, 1);
    k.addEdge(1, 2);
    k.addEdge(1, 5);
    k.addEdge(2, 3);
    k.addEdge(2, 4);
    k.addEdge(5, 3);
    k.addEdge(5, 6);
    k.addEdge(3, 6);

    k.printGraph();
    std::cout << "Is strongly connected: " << k.isStronglyConnected() << "\n\n";


    Graph j(7);
    j.addEdge(0, 1);
    j.addEdge(1, 2);
    j.addEdge(2, 3);
    j.addEdge(3, 4);
    j.addEdge(4, 5);
    j.addEdge(5, 6);
    
    j.printGraph();
    j.isStronglyConnected();
    std::cout << "Is strongly connected: " << k.isStronglyConnected() << "\n\n";


}
