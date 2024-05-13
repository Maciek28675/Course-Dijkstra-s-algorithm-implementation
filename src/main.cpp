#include <iostream>
#include <vector>
#include <unordered_map>
#include "AdjencyMatrix.hpp";
#include "AdjencyList.hpp";
#include "MinHeap.hpp"
#include "Node.hpp"

int main()
{
    std::vector<std::unordered_map<int, int>> data1 = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {2, 8}, {7, 11}},
        {{1, 8}, {3, 7}, {8, 2}},
    };

	AdjencyList g1(9);

    AdjencyList g3(data1, data1.size());

    g3.display();

    std::cout << "\n----------------------------\n";

    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 7, 8);
    g1.addEdge(1, 2, 8);
    g1.addEdge(1, 7, 11);
    g1.addEdge(2, 3, 7);
    g1.addEdge(2, 8, 2);
    g1.addEdge(2, 5, 4);
    g1.addEdge(3, 4, 9);
    g1.addEdge(3, 5, 14);
    g1.addEdge(4, 5, 10);
    g1.addEdge(5, 6, 2);
    g1.addEdge(6, 7, 1);
    g1.addEdge(6, 8, 6);
    g1.addEdge(7, 8, 7);

    g1.display();

    std::cout << '\n';

    g1.dijkstraToAll(2);
    g1.dijkstraToVertex(2, 5);

    std::vector<std::vector<int>> data = { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    AdjencyMatrix g2(data, data.size());

    g2.display();

    std::cout << '\n';

    g2.dijkstraToAll(0);
    g2.dijkstraToVertex(0, 5);

	return 0;
}