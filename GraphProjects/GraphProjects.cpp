// GraphProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

int main()
{
    Graph k(7, false);
    k.addEdge(0, 1);
    k.addEdge(1, 2);
    k.addEdge(3, 4);
    k.addEdge(5, 3);
    k.addEdge(5, 6);
    k.addEdge(3, 6);

    //k.printGraph();
    k.printConnectedComponents();

    //printContainer(visited);


}
