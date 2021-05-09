// GraphProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

int main()
{
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 4);

    // remove edge 3 -> 4
    if (g.willCauseSeparateComponents(3, 4))
        cout << "Yes, separate components created due to deletion of edge 3 -> 4" << endl;
    else
        cout << "No, separate components not created due to deletion of edge 3 -> 4" << endl;

    // remove edge 1 -> 2
    if (g.willCauseSeparateComponents(1, 2))
        cout << "Yes, separate components created due to deletion of edge 1 -> 2" << endl;
    else
        cout << "No, separate components not created due to deletion of edge 1 -> 2" << endl;


}
