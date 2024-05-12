#ifndef ADJENCY_LIST_HPP
#define ADJENCY_LIST_HPP

#include "Graph.hpp"
#include <vector>
#include <unordered_map>

class AdjencyList : public Graph
{
private:
	std::vector<std::unordered_map<int, int>> adjencyList_;
	size_t numberOfVertices_;
public:
	AdjencyList();
	AdjencyList(size_t);
	//AdjencyMatrix(std::vector<std::vector<int>>, size_t);
	~AdjencyList();

	void addEdge(int start, int end, int weight) override;
	void addVertex() override;

	void deleteEdge(int start, int end) override;
	void deleteVertex(int vertex) override;

	void display() override;

	int getWeight(int start, int end) override;

	void dijkstraToAll(int source) override;
};

#endif