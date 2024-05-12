#include "AdjencyList.hpp"
#include <vector>
#include <unordered_map>
#include <iostream>

// Create empty List
AdjencyList::AdjencyList()
{
	numberOfVertices_ = 0;
}

// Initialize List of specified size
AdjencyList::AdjencyList(size_t numberOfVerticies) : adjencyList_(numberOfVerticies), numberOfVertices_(numberOfVerticies){}

AdjencyList::~AdjencyList() {}

void AdjencyList::addEdge(int start, int end, int weight)
{
	adjencyList_[start][end] = weight;
	adjencyList_[end][start] = weight;
}

void AdjencyList::addVertex()
{
	// TODO: complete addVertex implementation
}

void AdjencyList::deleteEdge(int start, int end)
{
	adjencyList_[start][end] = 0;
	adjencyList_[end][start] = 0;
}

void AdjencyList::deleteVertex(int vertex)
{
	// TODO: complete deleteVertex implementation
}

void AdjencyList::display()
{
	for (int i = 0; i < numberOfVertices_; i++)
	{
		std::cout << i << " -> ";

		for (const auto& it : adjencyList_[i])
		{
			std::cout << "{" << it.first << ", " << it.second << "} -> ";
		}

		std::cout << '\n';
	}
}

int AdjencyList::getWeight(int start, int end)
{
	return adjencyList_[start][end];
}

void AdjencyList::dijkstraToAll(int source)
{

}