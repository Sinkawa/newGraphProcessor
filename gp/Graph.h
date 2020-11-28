//
// Created by MarkN on 26.11.2020.
//

#ifndef ANOTHERONE_GRAPH_H
#define ANOTHERONE_GRAPH_H

#include <vector>
#include "GraphNode.h"
#include "Edges.h"
#include "GraphDefines.h"

namespace gp {

    class Graph {
        bool isOriented;
        _NODELIST *listOfNodes;
        _WEDGELIST *listOfEdges;
        _WEIGHTMATRIX *weightMatrix;

        int lastId;
        int bias;
    public:
        explicit Graph(bool _isOriented = false);

        _WEIGHTMATRIX *getWeightMatrix();

        _NODELIST *getListOfNodes();

        _WEDGELIST *getListOfEdges();

        int getBias() const;

        void setListOfNodes(_NODELIST list);

        void setListOfEdges(_WEDGELIST list);

        void setWeightMatrix(_WEIGHTMATRIX matrix);


        int createGraphByEdges();

        void createGraphByWeightMatrix();

        void createNodes(int amount);

        void createListOfEdges();


        void recalculateBias();

        void sortListOfEdges();

        void clearList();

        ~Graph();

    private:

        int findMaxId();

        void createListOfAdjacentNodes(int index);

        int createWeightMatrixFromEdges();

    };
}

#endif //ANOTHERONE_GRAPH_H
