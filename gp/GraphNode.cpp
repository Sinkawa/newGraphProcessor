//
// Created by MarkN on 26.11.2020.
//

#include "GraphNode.h"

namespace gp {

    GraphNode::GraphNode(int id) : id(id) {
        this->checkStatus = false;
        this->listOfAdjacentNodes = nullptr;
    }

    GraphNode::GraphNode(int id, _NODELIST listOfAdjacentNodes) : id(id) {
        this->checkStatus = false;
        this->listOfAdjacentNodes = new _NODELIST;
        *this->listOfAdjacentNodes = std::move(listOfAdjacentNodes);
    }

    int GraphNode::getId() const {
        return this->id;
    }

    bool GraphNode::isChecked() const {
        return this->checkStatus;
    }

    _NODELIST *GraphNode::getListOfAdjacentNodes() {
        return listOfAdjacentNodes;
    }

    void GraphNode::setCheck(bool status) {
        this->checkStatus = status;
    }

    void GraphNode::addAdjacentNode(_NODE *adjacentNode) {
        if (this->listOfAdjacentNodes == nullptr) {
            this->listOfAdjacentNodes = new _NODELIST;
            this->listOfAdjacentNodes->push_back(adjacentNode);
        } else if (!contains(adjacentNode)) {
            this->listOfAdjacentNodes->push_back(adjacentNode);

            for (auto i = this->listOfAdjacentNodes->begin();
                 i < this->listOfAdjacentNodes->end(); i++) {

                if ((*i)->getId() > adjacentNode->getId()) {
                    this->listOfAdjacentNodes->insert(i, 1, adjacentNode);
                    return;
                }
            }
        }
    }

    bool GraphNode::removeAdjacentNode(_NODE *adjacentNode) {
        if (!contains(adjacentNode)) {
            return false;
        }
        return removeNode(adjacentNode);;
    }

    bool GraphNode::contains(_NODE *adjacentNode) {
        for (auto &listOfAdjacentNode : *listOfAdjacentNodes) {
            if (listOfAdjacentNode == adjacentNode) {
                return true;
            }
        }
        return false;
    }

    bool GraphNode::removeNode(_NODE *adjacentNode) {
        for (int i = 0; i < listOfAdjacentNodes->size(); i++) {
            if (listOfAdjacentNodes->at(i) == adjacentNode) {
                this->listOfAdjacentNodes->erase(listOfAdjacentNodes->begin() + i);
                return true;
            }
        }
        return false;
    }

    GraphNode::~GraphNode() {
        delete listOfAdjacentNodes;
    }

    _NODE *GraphNode::findAdjById(int id) {
        for (int i = 0; i < this->listOfAdjacentNodes->size(); i++) {
            if (this->listOfAdjacentNodes->at(i)->getId() == id) {
                return this->listOfAdjacentNodes->at(i);
            }
        }
        return nullptr;
    }
}
