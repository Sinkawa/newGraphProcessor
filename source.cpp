#include <iostream>
#include "GraphProcessor.h"


void print(std::vector<int> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << i << " " << list.at(i) << std::endl;
    }
}

int main()
{
    auto* graph = new gp::Graph;
    gp::GraphHandler graphHandler(graph);

    auto* list = new std::vector<gp::weightedEdge>;
    *list = gp::getListOfEdgesFromFile("data.txt");
    if (list->size() == 0) {
        return -404;
    }

    graph->setListOfEdges(*list);
    delete list;

    graph->createGraphByEdges();

    std::vector<int> listOfWeights = graphHandler.algDijkstra(1);

    print(listOfWeights);

    system("pause");
    return 0;
}