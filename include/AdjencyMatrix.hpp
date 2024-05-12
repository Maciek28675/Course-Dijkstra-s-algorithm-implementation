#ifndef ADJENCY_MATRIX_HPP
#define ADJENCY_MATRIX_HPP

#include <vector>
#include "Graph.hpp"

class AdjencyMatrix : public Graph
{
private:
	std::vector<std::vector<int>> adjencyMatrix_;
	size_t numberOfVerticies_;

public:
	AdjencyMatrix();
	AdjencyMatrix(size_t);
	//AdjencyMatrix(std::vector<std::vector<int>>, size_t);
	~AdjencyMatrix();

	void addEdge(int start, int end, int weight) override;
	void addVertex() override;

	void deleteEdge(int start, int end) override;
	void deleteVertex(int vertex) override;

	void display() override;

	int getWeight(int start, int end) override;

	void dijkstraToAll(int source) override;
};

#endif