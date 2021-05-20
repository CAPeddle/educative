// GraphColouring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Graph.h"
#include <iostream>

int main()
{
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	cout << "Coloring of graph 1 \n";
	g1.greedyColoring();

	Graph g2(5);
	g2.addEdge(0, 1);
	g2.addEdge(0, 2);
	g2.addEdge(1, 2);
	g2.addEdge(1, 4);
	g2.addEdge(2, 4);
	g2.addEdge(4, 3);
	cout << "\nColoring of graph 2 \n";
	g2.greedyColoring();

	return 0;
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
