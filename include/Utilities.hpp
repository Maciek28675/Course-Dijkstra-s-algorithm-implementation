#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<int> generateDataSet(int size, int seed = time(NULL), int start = 0, int end = 100)
{
	srand(seed);
	std::vector<int> dataSet;

	for (int i = 0; i < size; i++)
	{
		int random = (rand() % end) + start;
		dataSet.push_back(random);
	}

	return dataSet;
}

void measurePerformance(int repetitions, int dataSetSize)
{
	//TODO: finish measurePerformance method
}
#endif