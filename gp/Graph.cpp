//
// Created by MarkN on 26.11.2020.
//

#include "Graph.h"

#include <utility>
#include <climits>

namespace gp {

    Graph::Graph(bool _isOriented) : isOriented(_isOriented) {
        this->lastId = 0;
        this->weightMatrix = nullptr;
        this->listOfNodes = nullptr;
        this->listOfEdges = nullptr;
        this->bias = 0;
    }

    _NODELIST *Graph::getListOfNodes() {
        return this->listOfNodes;
    }

    _WEDGELIST *Graph::getListOfEdges() {
        return this->listOfEdges;
    }

    //rework needed
    void Graph::createGraphByWeightMatrix() {
        return;
    }

    void Graph::createNodes(int amount) {
        if (this->listOfNodes == nullptr) {
            this->listOfNodes = new _NODELIST;
        }

        for (int index = 0; index < amount; index++) {
            this->listOfNodes->push_back(new _NODE(index + this->lastId));
        }

        this->lastId += amount;
    }

    void Graph::setListOfEdges(_WEDGELIST list) {
        if (this->listOfEdges != nullptr) {
            delete this->listOfEdges;
        }
        this->listOfEdges = new _WEDGELIST;
        *this->listOfEdges = std::move(list);
    }

    void Graph::createListOfEdges() {
        for (int index = 0; index < this->weightMatrix->size(); index++) {
            for (int pos = 0; pos < this->weightMatrix->size(); pos++) {
                if (this->weightMatrix->at(index).at(pos) == 1) {
                    this->listOfEdges->push_back(_WEDGE(index, pos, -1, this->isOriented));
                }
            }
        }
    }

    int Graph::getBias() const {
        return this->bias;
    }

    int Graph::createGraphByEdges() {
        if (this->listOfEdges == nullptr) {
            return -1;
        }

        if (this->listOfNodes == nullptr || this->listOfNodes->size() < findMaxId()) {
            clearList();
            createNodes(findMaxId());
        }
        recalculateBias();


        for (auto edge : *this->listOfEdges) {
            this->listOfNodes->at(edge.firstId + this->bias)->addAdjacentNode(
                    this->listOfNodes->at(edge.secondId + this->bias));
            this->listOfNodes->at(edge.secondId + this->bias)->addAdjacentNode(
                    this->listOfNodes->at(edge.firstId + this->bias));
        }

        createWeightMatrixFromEdges();
        return 0;
    }

    void Graph::recalculateBias() {
        this->bias = this->listOfNodes->at(this->listOfNodes->size() - 1)->getId() - findMaxId();
    }

    void Graph::createListOfAdjacentNodes(int index) {
        _NODELIST list;
        for (int pos = 0; pos < this->weightMatrix->size(); pos++) {
            if (this->weightMatrix->at(index).at(pos) != INT_MAX) {
                this->listOfNodes->at(index)->addAdjacentNode(this->listOfNodes->at(pos));
            }
        }
    }

    void Graph::clearList() {
        if (this->listOfNodes != nullptr) {
            for (int index = 0; index < this->listOfNodes->size(); index++) {
                delete this->listOfNodes->at(index);
            }

            delete this->listOfNodes;
        }
        this->lastId = 0;
    }

    int Graph::findMaxId() {
        int result = -1;
        for (int i = 0; i < this->listOfEdges->size(); i++) {
            if (this->listOfEdges->at(i).secondId > result) {
                result = this->listOfEdges->at(i).secondId;
            }
        }

        return result;
    }

    void Graph::sortListOfEdges() {
        for (int i = 1; i < listOfEdges->size(); i++) {
            for (int j = 0; j < listOfEdges->size() - i; j++) {
                if (listOfEdges->at(j).firstId > listOfEdges->at(j + 1).firstId) {
                    std::swap(listOfEdges->at(j), listOfEdges->at(j + 1));
                } else if (listOfEdges->at(j).firstId == listOfEdges->at(j + 1).firstId &&
                           listOfEdges->at(j).secondId > listOfEdges->at(j + 1).secondId) {
                    std::swap(listOfEdges->at(j), listOfEdges->at(j + 1));
                }
            }
        }
    }

    _WEIGHTMATRIX *Graph::getWeightMatrix() {
        return this->weightMatrix;
    }

    void Graph::setWeightMatrix(_WEIGHTMATRIX matrix) {
        if (this->weightMatrix != nullptr) {
            delete this->weightMatrix;
        }
        this->weightMatrix = new _WEIGHTMATRIX;
        *this->weightMatrix = std::move(matrix);
    }

    void Graph::setListOfNodes(_NODELIST list) {
        if (this->listOfNodes != nullptr) {
            clearList();
        }
        this->listOfNodes = new _NODELIST;
        *this->listOfNodes = std::move(list);
        this->lastId = this->listOfNodes->at(this->listOfNodes->size() - 1)->getId();
    }

    int Graph::createWeightMatrixFromEdges() {
        if (this->listOfEdges->empty()) {
            return -1;
        }

        if (this->listOfNodes->empty()) {
            createNodes(findMaxId());
        }

        if (this->weightMatrix != nullptr) {
            delete this->weightMatrix;
        }

        this->weightMatrix = new _WEIGHTMATRIX;
        this->weightMatrix->resize(this->listOfNodes->size());
        for (int row = 0; row < this->weightMatrix->size(); row++) {
            this->weightMatrix->at(row).resize(this->listOfNodes->size());
            for (int cell = 0; cell < this->weightMatrix->at(row).size(); cell++) {
                this->weightMatrix->at(row).at(cell) = INT_MAX;
            }
        }

        for (auto &listOfEdge : *this->listOfEdges) {
            this->weightMatrix->at(listOfEdge.firstId + this->bias).at(
                    listOfEdge.secondId + this->bias) = listOfEdge.weight;
        }
        return 0;
    }

    Graph::~Graph() {
        delete this->weightMatrix;
        delete this->listOfEdges;
        for (auto & node : *this->listOfNodes)
        {
            delete node;
        }
        delete this->listOfNodes;
    }
}