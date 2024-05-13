#ifndef GRAPH_HPP
#define GRAPH_HPP

class AdjencyMatrix;

class AdjencyList;

class Graph
{
public:
	virtual void addEdge(int start, int end, int weight) = 0;
	virtual void addVertex() = 0;

	virtual void deleteEdge(int start, int end) = 0;
	virtual void deleteVertex(int vertex) = 0;

	virtual void display() = 0;

	virtual int getWeight(int start, int end) = 0;

	virtual void dijkstraToAll(int source) = 0;
	virtual void dijkstraToVertex(int source, int destination) = 0;
};

#endif