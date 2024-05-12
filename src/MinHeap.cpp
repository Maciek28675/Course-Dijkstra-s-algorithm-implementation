#include "MinHeap.hpp"
#include <iostream>

//Create an empty queue
MinHeap::MinHeap()
{
	std::vector<Node> heap;
	heap_ = heap;
	size_ = 0;
}

//Initialize queue with data
MinHeap::MinHeap(std::vector<Node> heap, size_t size) : heap_(heap), size_(size)
{
	// Start index is the last non-leaf index
	int startIndex = (size_ / 2) - 1;

	for (int i = startIndex; i >= 0; i--)
	{
		heapifyDown(i);
	}
}

//Copy constructor
MinHeap::MinHeap(const MinHeap& copy)
{
	heap_ = copy.heap_;
	size_ = copy.size_;
}


MinHeap::~MinHeap() {}

//Ensure that heap property is satisfied while moving up
void MinHeap::heapifyUp(int index)
{
	int parentIndex = (index - 1) / 2;

	while ((index > 0) && (heap_[index].weight < heap_[parentIndex].weight))
	{
		std::swap(heap_[index], heap_[parentIndex]);
		index = parentIndex;
		parentIndex = (index - 1) / 2;
	}
}

//Ensure that heap property is satisfied while moving down
void MinHeap::heapifyDown(int index)
{
	//If there is only one node, the heap property is obviously satisfied
	if (size_ == 1)
		return;

	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	int smallestElementIndex = index;

	if ((leftChildIndex < size_) && (heap_[leftChildIndex].weight < heap_[smallestElementIndex].weight))
		smallestElementIndex = leftChildIndex;

	if ((rightChildIndex < size_) && (heap_[rightChildIndex].weight < heap_[smallestElementIndex].weight))
		smallestElementIndex = rightChildIndex;

	if (smallestElementIndex != index)
	{
		std::swap(heap_[index], heap_[smallestElementIndex]);
		heapifyDown(smallestElementIndex);
	}
}

//Insert new node into queue while satisfying heap property
void MinHeap::insert(int vertex, int weight)
{
	heap_.push_back({ vertex, weight });
	heapifyUp(size_ - 1);
	size_++;
}

//Get element with highest weight and delete it
Node MinHeap::exctractMin()
{
	Node oldRoot = heap_[0];
	heap_[0] = heap_[size_ - 1];

	heap_.pop_back();
	size_--;
	heapifyDown(0);

	return oldRoot;
}

//Get element with highest weight
Node MinHeap::findMin()
{
	return heap_[0];
}

//Increase or decrase property of an element at index
void MinHeap::modifyKey(int vertex, int weight)
{
	int index = 0;

	for (int i = 0; i < size_; i++)
	{
		if (heap_[i].vertex == vertex)
		{
			index = i;
			break;
		}
	}

	//If weight of found element is the same as specified weight do nothing
	if (heap_[index].weight == weight)
		return;

	//Incerease key
	if (weight > heap_[index].weight)
	{
		heap_[index].weight = weight;
		heapifyUp(index);
	}

	//Decrease key
	else if (weight < heap_[index].weight)
	{
		heap_[index].weight = weight;
		heapifyDown(index);
	}
}

size_t MinHeap::getSize()
{
	return size_;
}

//Display queue in right order (grouped by levels)
void MinHeap::display()
{
	if (size_ == 0)
	{
		std::cout << "Heap is empty" << std::endl;
		return;
	}

	int level = 0;
	int levelSize = 1;
	int currentSize = 0;

	for (int i = 0; i < size_; ++i)
	{
		std::cout << heap_[i].vertex << " ";

		if (++currentSize == levelSize)
		{
			std::cout << std::endl;
			levelSize *= 2;
			currentSize = 0;
			++level;
		}
	}

	std::cout << std::endl;
}

int MinHeap::getElement(int index)
{
	return heap_[index].vertex;
}


int MinHeap::getWeight(int index)
{
	return heap_[index].weight;
}


void MinHeap::setElement(int index, int vertex)
{
	heap_[index].vertex = vertex;
}