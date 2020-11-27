//
// Created by MarkN on 26.11.2020.
//

#include "GraphNode.h"

namespace gp
{

    GraphNode::GraphNode(int id) : id(id)
    {
        this->checkStatus = false;
        this->listOfAdjacentNodes = nullptr;
    }

    GraphNode::GraphNode(int id, std::vector<GraphNode*> listOfAdjacentNodes) : id(id)
    {
        this->checkStatus = false;
        this->listOfAdjacentNodes = new std::vector<GraphNode*>;
        *this->listOfAdjacentNodes = std::move(listOfAdjacentNodes);
    }

    int GraphNode::getId() const
    {
        return this->id;
    }

    bool GraphNode::isChecked() const
    {
        return this->checkStatus;
    }

    std::vector<GraphNode*>* GraphNode::getListOfAdjacentNodes()
    {
        return listOfAdjacentNodes;
    }

    void GraphNode::setCheck(bool status)
    {
        this->checkStatus = status;
    }

    void GraphNode::addAdjacentNode(GraphNode* adjacentNode)
    {
        if (listOfAdjacentNodes == nullptr)
        {
            listOfAdjacentNodes = new std::vector<GraphNode *>();
            listOfAdjacentNodes->push_back(adjacentNode);
        } else if (!contains(adjacentNode))
        {
            listOfAdjacentNodes->push_back(adjacentNode);
        }
    }

    bool GraphNode::removeAdjacentNode(GraphNode* adjacentNode)
    {
        if (!contains(adjacentNode))
        {
            return false;
        }
        return removeNode(adjacentNode);;
    }

    bool GraphNode::contains(GraphNode* adjacentNode)
    {
        for (auto & listOfAdjacentNode : *listOfAdjacentNodes)
        {
            if (listOfAdjacentNode == adjacentNode)
            {
                return true;
            }
        }
        return false;
    }

    bool GraphNode::removeNode(GraphNode* adjacentNode)
    {
        for (int i = 0; i < listOfAdjacentNodes->size(); i++)
        {
            if (listOfAdjacentNodes->at(i) == adjacentNode)
            {
                this->listOfAdjacentNodes->erase(listOfAdjacentNodes->begin()+i);
                return true;
            }
        }
        return false;
    }

    GraphNode::~GraphNode()
    {
        delete listOfAdjacentNodes;
    }
}
