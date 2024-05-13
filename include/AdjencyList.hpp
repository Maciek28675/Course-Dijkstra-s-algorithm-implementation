#ifndef ADJENCY_LIST_HPP
#define ADJENCY_LIST_HPP

#include "Graph.hpp"
#include <vector>
#include <unordered_map>

class AdjencyList : public Graph
{
private:
	// Data structure looks like this: adjencyList_[startVertex][endVertex] = weight
	// At every index there is a 'list' of its neighbours and corresponding weights
	std::vector<std::unordered_map<int, int>> adjencyList_;
	size_t numberOfVertices_;

public:
	AdjencyList();
	AdjencyList(size_t);
	AdjencyList(std::vector<std::unordered_map<int, int>>, size_t);
	~AdjencyList();

	void addEdge(int start, int end, int weight) override;
	void addVertex() override;

	void deleteEdge(int start, int end) override;
	void deleteVertex(int vertex) override;

	void display() override;

	int getWeight(int start, int end) override;

	void dijkstraToAll(int source) override;
	void dijkstraToVertex(int source, int destination) override;
};

#endif