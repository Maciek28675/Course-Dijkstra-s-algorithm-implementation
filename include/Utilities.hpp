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

	// Generate random weights (number of weights is defined by graph density
	// Generate a set of random start veritces
	// Generate a set of random end vertices
	// Insert edges to random selected start and end vertices
	// Measure time of algoritm a few times
	// Repeat process 100 times, each time with new random instance
	// return avarage time
	// Do this for every data type, size, density
}
#endif