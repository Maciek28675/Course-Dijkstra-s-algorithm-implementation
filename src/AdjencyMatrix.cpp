#include "AdjencyMatrix.hpp"
#include "MinHeap.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

#define INFINITY std::numeric_limits<int>::max()

// Create empty matrix
AdjencyMatrix::AdjencyMatrix()
{
	numberOfVerticies_ = 0;
}

// Initialize matrix with zeros
AdjencyMatrix::AdjencyMatrix(size_t numberOfVerticies): adjencyMatrix_(numberOfVerticies, std::vector<int>(numberOfVerticies, 0)),
														numberOfVerticies_(numberOfVerticies) {}

AdjencyMatrix::AdjencyMatrix(std::vector<std::vector<int>> dataSet, size_t size) : adjencyMatrix_(dataSet), numberOfVerticies_(size) {}

AdjencyMatrix::~AdjencyMatrix(){}

void AdjencyMatrix::addEdge(int start, int end, int weight)
{
	adjencyMatrix_[start][end] = weight;
	adjencyMatrix_[end][start] = weight;
}

void AdjencyMatrix::addVertex()
{
	// TODO: complete addVertex implementation
}

void AdjencyMatrix::deleteEdge(int start, int end)
{
	adjencyMatrix_[start][end] = 0;
	adjencyMatrix_[end][start] = 0;
}

void AdjencyMatrix::deleteVertex(int vertex)
{
	// TODO: complete deleteVertex implementation
}

void AdjencyMatrix::display()
{
	// Display columns
	std::cout << "   ";

	for (int i = 0; i < numberOfVerticies_; i++)
		std::cout << i << " ";

	std::cout << "\n   ";

	for (int i = 0; i < numberOfVerticies_; i++)
		std::cout << "--";

	std::cout << '\n';

	// Display weights
	for (int row = 0; row < numberOfVerticies_; row++)
	{
		std::cout << row << "| ";

		for (int column = 0; column < numberOfVerticies_; column++)
		{
			std::cout << adjencyMatrix_[row][column] << " ";
		}

		std::cout << '\n';
	}
}

int AdjencyMatrix::getWeight(int start, int end)
{
	return adjencyMatrix_[start][end];
}

void AdjencyMatrix::dijkstraToAll(int source)
{
	//Priority queue to select minimum distance nodes
	MinHeap pq;

	// Vector to store distances to each vertex. At the beginning, all are initialized as infinity
	std::vector<int> distances(numberOfVerticies_, INFINITY);

	for (int i = 0; i < numberOfVerticies_; i++)
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
		for (int i = 0; i < numberOfVerticies_; i++)
		{
			int tempVertex = i;
			int tempWeight = adjencyMatrix_[u][i];

			//
			if ((distances[tempVertex] > distances[u] + tempWeight) &&
				(adjencyMatrix_[u][i] != 0) &&
				(distances[u] != INFINITY))
			{
				distances[tempVertex] = distances[u] + tempWeight;
				pq.insert(tempVertex, distances[tempVertex]);
			}
		}
	}

	/*
	std::cout << "Vertex | Distance from " << source << '\n';
	std::cout << "------------------------\n";

	for (int i = 0; i < numberOfVerticies_; i++)
	{
		std::cout << std::internal << std::setw(4) << i << " " << std::right << std::setw(12) << distances[i] << '\n';
	}
	*/
}

void AdjencyMatrix::dijkstraToVertex(int source, int destination)
{
	//Priority queue to select minimum distance nodes
	MinHeap pq;

	// Vector to store distances to each vertex. At the beginning, all are initialized as infinity
	std::vector<int> distances(numberOfVerticies_, INFINITY);

	for (int i = 0; i < numberOfVerticies_; i++)
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

		if (u == destination)
			break;

		// Get through all vertices adjecent to u
		for (int i = 0; i < numberOfVerticies_; i++)
		{
			int tempVertex = i;
			int tempWeight = adjencyMatrix_[u][i];

			//
			if ((distances[tempVertex] > distances[u] + tempWeight) &&
				(adjencyMatrix_[u][i] != 0) &&
				(distances[u] != INFINITY))
			{
				distances[tempVertex] = distances[u] + tempWeight;
				pq.insert(tempVertex, distances[tempVertex]);
			}
		}
	}

	//std::cout << "Shortest path from " << source << " to " << destination << ": " << distances[destination] << '\n';
}

// Check wether there is an edge beetwen vertices
bool AdjencyMatrix::isEdge(int start, int end)
{
	if (adjencyMatrix_[start][end] == 0)
		return false;
	else
		return true;
}