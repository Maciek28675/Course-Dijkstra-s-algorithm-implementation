#include "AdjencyMatrix.hpp"
#include "MinHeap.hpp"
#include <iostream>
#include <vector>

// Create empty matrix
AdjencyMatrix::AdjencyMatrix()
{
	numberOfVerticies_ = 0;
}

// Initialize matrix with zeros
AdjencyMatrix::AdjencyMatrix(size_t numberOfVerticies): adjencyMatrix_(numberOfVerticies, std::vector<int>(numberOfVerticies, 0)),
														numberOfVerticies_(numberOfVerticies) {}

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
	//Priority queue for storing processed vertices
	MinHeap pq;

	// Container to store distances to each vertex. At the beginning, all are initialized as infinity
	std::vector<int> distances(numberOfVerticies_, INFINITY);

	distances[source] = 0;

	for (int i = 1; i < numberOfVerticies_; i++)
	{
		pq.insert(i, distances[i]);
	}

	while (pq.getSize() != 0)
	{
		int u = pq.exctractMin().vertex;

	}
}