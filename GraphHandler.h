//
// Created by MarkN on 26.11.2020.
//

#ifndef ANOTHERONE_GRAPHHANDLER_H
#define ANOTHERONE_GRAPHHANDLER_H

#include "GraphNode.h"
#include "Graph.h"

namespace gp
{
    class GraphHandler {
        Graph* graph;
        int bias;
    public:
        explicit GraphHandler(Graph* GraphNode);

        std::vector<int> algDijkstra(int id);

    private:
        void recalculateBias();
        static int findFirst(int id, std::vector<weightedEdge>* list);
        void sort(std::vector<int>& idList, std::vector<int>* param);

        static std::vector<weightedEdge>* expandList(std::vector<weightedEdge>* list);
        static std::vector<weightedEdge>* sortList(std::vector<weightedEdge>* list);
        std::vector<int> *algDijkstraR(int startIndex, std::vector<int> *result, std::vector<weightedEdge> *edges);
    };
}

#endif //ANOTHERONE_GRAPHHANDLER_H
