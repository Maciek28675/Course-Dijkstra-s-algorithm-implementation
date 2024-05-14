#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "AdjencyMatrix.hpp"
#include "AdjencyList.hpp"
#include "Timer.hpp"

void generateMatrix(AdjencyMatrix& graph, int vertices, int edges, int seed = time(NULL), int start = 0, int end = 20)
{
	srand(seed);
	int assignedEdges = 0;

	while (assignedEdges <= edges)
	{
		int startVertex = (rand() % vertices) + 0;
		int endVertex = (rand() % vertices) + 0;

		if(startVertex != endVertex && !graph.isEdge(startVertex, endVertex))
		{
			int weight = (rand() % end) + 0;

			graph.addEdge(startVertex, endVertex, weight);
			graph.addEdge(endVertex, startVertex, weight);

			assignedEdges++;
		}
	}
}

void generateList(AdjencyList& graph, int vertices, int edges, int seed = time(NULL), int start = 0, int end = 20)
{
	srand(seed);
	int assignedEdges = 0;

	while (assignedEdges <= edges)
	{
		int startVertex = (rand() % vertices) + 0;
		int endVertex = (rand() % vertices) + 0;

		if (startVertex != endVertex)
		{
			int weight = (rand() % end) + 0;

			graph.addEdge(startVertex, endVertex, weight);
			graph.addEdge(endVertex, startVertex, weight);

			assignedEdges++;
		}
	}
}

void measurePerformance(int vertices, int edges, int maxEdge)
{
	double averageTime = 0.0;
	double sum = 0.0;
	double duration = 0.0;

	for (int i = 0; i < 100; i++)
	{
		AdjencyList g1(vertices);
		generateList(g1, vertices, edges, time(NULL), 0, maxEdge);

		Timer timer;
		
		timer.start();
		g1.dijkstraToAll(0);
		timer.stop();

		duration = timer.getDuration();
		sum += duration;
	}

	averageTime = sum / 100;

	std::cout << averageTime << '\n';
}
#endif