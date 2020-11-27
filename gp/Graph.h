//
// Created by MarkN on 26.11.2020.
//

#ifndef ANOTHERONE_GRAPH_H
#define ANOTHERONE_GRAPH_H

#include <vector>
#include "GraphNode.h"
#include "Edges.h"

namespace gp
{

    class Graph {
        std::vector<gp::GraphNode*>* listOfNodes;
        std::vector<std::vector<int>>* adjacencyMatrix;
        std::vector<weightedEdge>* listOfEdges;
        int lastId;
        int bias;
    public:
        Graph();

        std::vector<gp::GraphNode*>* getListOfNodes();
        std::vector<weightedEdge>* getListOfEdges();
        int getBias() const;

        void setAdjacencyMatrix(std::vector<std::vector<int>> adjacencyMatrix);
        void setListOfEdges(std::vector<weightedEdge> list);

        int createGraphByEdges();
        void createGraphByAdjMatrix();
        void createNodes(int amount);
        void createListOfEdges();

        void sortListOfEdges();
        void clearList();
    private:

        int findMaxId();

        void createListOfAdjacentNodes(int index);
    };
}

#endif //ANOTHERONE_GRAPH_H
