#include <iostream>
#include <vector>
#include "AdjencyMatrix.hpp";
#include "AdjencyList.hpp";
#include "MinHeap.hpp"
#include "Node.hpp"

int main()
{
	AdjencyList g1(9);

    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 7, 8);
    g1.addEdge(1, 2, 8);
    g1.addEdge(1, 7, 11);
    g1.addEdge(2, 3, 7);
    g1.addEdge(2, 8, 2);
    g1.addEdge(2, 5, 4);
    g1.addEdge(3, 4, 9);
    g1.addEdge(3, 5, 14);
    g1.addEdge(4, 5, 10);
    g1.addEdge(5, 6, 2);
    g1.addEdge(6, 7, 1);
    g1.addEdge(6, 8, 6);
    g1.addEdge(7, 8, 7);

    g1.dijkstraToAll(0);

	return 0;
}