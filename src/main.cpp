#include <iostream>
#include <vector>
#include "AdjencyMatrix.hpp";
#include "AdjencyList.hpp";
#include "MinHeap.hpp"
#include "Node.hpp"

int main()
{
	AdjencyMatrix g1(10);
	g1.addEdge(2, 4, 7);
	g1.deleteEdge(2, 4);
	g1.display();

	AdjencyList g2(10);
	g2.addEdge(2, 4, 7);
	g2.addEdge(2, 5, 3);
	g2.deleteEdge(2, 4);
	g2.display();
	
	std::vector<Node> data{ 
		{4, 4},
		{2, 2},
		{3, 3},
		{8, 8},
		{5, 5},
		{6, 6},
		{9, 9}
	};

	MinHeap pq(data, data.size());
	pq.display();

	return 0;
}