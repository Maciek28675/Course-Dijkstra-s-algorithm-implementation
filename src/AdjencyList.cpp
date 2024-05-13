#include "AdjencyList.hpp"
#include "MinHeap.hpp"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <limits>
#include <iomanip>

#define INFINITY std::numeric_limits<int>::max()

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
	//Priority queue to select minimum distance nodes
	MinHeap pq;

	// Vector to store distances to each vertex. At the beginning, all are initialized as infinity
	std::vector<int> distances(numberOfVertices_, INFINITY);

	for (int i = 0; i < numberOfVertices_; i++)
	{
		pq.insert(i, distances[i]);
	}

	// Distance to source is 0
	distances[source] = 0;
	pq.modifyKey(source, 0);

	while (pq.getSize() != 0)
	{
		// Temporary vertex with shortest distance
		int u = pq.exctractMin().vertex;

		// Get through all vertices adjecent to u
		for (const auto& it : adjencyList_[u])
		{
			int tempVertex = it.first;
			int tempWeight = it.second;

			//
			if (distances[tempVertex] > distances[u] + tempWeight)
			{
				distances[tempVertex] = distances[u] + tempWeight;
				pq.insert(tempVertex, distances[tempVertex]);
			}
		}
	}

	std::cout << "Vertex | Distance from "<< source << '\n';
	std::cout << "------------------------\n";

	for (int i = 0; i < numberOfVertices_; i++)
	{
		std::cout << std::internal << std::setw(4) << i << " " << std::right << std::setw(12) << distances[i] << '\n';
	}
} 