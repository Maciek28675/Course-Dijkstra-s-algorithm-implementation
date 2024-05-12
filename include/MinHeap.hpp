#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include "Node.hpp"
#include <vector>

class MinHeap
{
private:
	std::vector<Node> heap_;
	size_t size_;

	void heapifyUp(int index);
	void heapifyDown(int index);

public:
	MinHeap();
	MinHeap(std::vector<Node>, size_t);
	MinHeap(const MinHeap& copy);
	~MinHeap();

	void insert(int vertex, int weight);
	Node exctractMin();
	Node findMin();
	void modifyKey(int vertex, int weight);
	size_t getSize();
	void display();

	int getElement(int index);
	int getWeight(int index);
	void setElement(int index, int vertex);
};

#endif