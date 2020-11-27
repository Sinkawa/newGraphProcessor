//
// Created by MarkN on 26.11.2020.
//

#include "Graph.h"

#include <utility>

namespace gp
{

    Graph::Graph() {
        this->lastId = 0;
        this->listOfNodes = nullptr;
        this->adjacencyMatrix = nullptr;
        this->listOfEdges = nullptr;
    }

    std::vector<gp::GraphNode*>* Graph::getListOfNodes()
    {
        return this->listOfNodes;
    }

    std::vector<weightedEdge>* Graph::getListOfEdges()
    {
        return this->listOfEdges;
    }

    void Graph::setAdjacencyMatrix(std::vector<std::vector<int>> adjacencyMatrix)
    {
        if (this->adjacencyMatrix != nullptr)
        {
            delete this->adjacencyMatrix;
        }
        this->adjacencyMatrix = new std::vector<std::vector<int>>;
        *this->adjacencyMatrix = std::move(adjacencyMatrix);
    };

    //rework needed
    void Graph::createGraphByAdjMatrix()
    {
        if (this->adjacencyMatrix == nullptr || this->listOfNodes->size() < this->adjacencyMatrix->size())
        {
            return;
        }

        for (int index = 0; index < this->adjacencyMatrix->size(); index++)
        {
            createListOfAdjacentNodes(index);
        }
    }

    void Graph::createNodes(int amount)
    {
        if (this->listOfNodes == nullptr)
        {
            this->listOfNodes = new std::vector<GraphNode *>;
        }

        for (int index = 0; index < amount; index++)
        {
            this->listOfNodes->push_back(new GraphNode(index + lastId));
        }

        this->lastId += amount;
    }

    void Graph::setListOfEdges(std::vector<weightedEdge> list)
    {
        if (this->listOfEdges != nullptr)
        {
            delete this->listOfEdges;
        }
        this->listOfEdges = new std::vector<weightedEdge>;
        *this->listOfEdges = std::move(list);
    }

    void Graph::createListOfEdges()
    {
        for (int index = 0; index < this->adjacencyMatrix->size(); index++)
        {
            for (int pos = 0; pos < this->adjacencyMatrix->size(); pos++)
            {
                if (this->adjacencyMatrix->at(index).at(pos) == 1)
                {
                    this->listOfEdges->push_back(weightedEdge(index, pos, -1));
                }
            }
        }
    }

    int Graph::getBias() const
    {
        return bias;
    }

    int Graph::createGraphByEdges()
    {
        if (listOfEdges == nullptr)
        {
            return -1;
        }

        if (this->listOfNodes == nullptr || this->listOfNodes->size() < findMaxId())
        {
            clearList();
            createNodes(findMaxId());
        }
        bias = this->listOfNodes->at(listOfNodes->size() - 1)->getId() - findMaxId();


        for (int i = 0; i < this->listOfEdges->size(); i++)
        {
            weightedEdge edge = this->listOfEdges->at(i);
            this->listOfNodes->at(edge.firstId + bias)->addAdjacentNode(this->listOfNodes->at(edge.secondId + bias));
            this->listOfNodes->at(edge.secondId + bias)->addAdjacentNode(this->listOfNodes->at(edge.firstId + bias));
        }


        return 0;
    }

    void Graph::createListOfAdjacentNodes(int index)
    {
        std::vector<GraphNode*> list;
        for (int pos = 0; pos < this->adjacencyMatrix->size(); pos++)
        {
            if (this->adjacencyMatrix->at(index).at(pos) == 1)
            {
                this->listOfNodes->at(index)->addAdjacentNode(this->listOfNodes->at(pos));
            }
        }
    }

    void Graph::clearList()
    {
        if (this->listOfNodes != nullptr) {
            for (int index = 0; index < this->listOfNodes->size(); index++) {
                delete this->listOfNodes->at(index);
            }

            delete this->listOfNodes;
        }
        this->lastId = 0;
    }

    int Graph::findMaxId()
    {
        int result = -1;
        for (int i = 0; i < this->listOfEdges->size(); i++)
        {
            if (this->listOfEdges->at(i).secondId > result)
            {
                result = this->listOfEdges->at(i).secondId;
            }
        }

        return result;
    }

    void Graph::sortListOfEdges() {
        for (int i = 1; i < listOfEdges->size(); i++) {
            for (int j = 0; j < listOfEdges->size() - i; j++) {
                if (listOfEdges->at(j).firstId > listOfEdges->at(j + 1).firstId) {
                    std::swap(listOfEdges->at(j), listOfEdges->at(j+1));
                } else if (listOfEdges->at(j).firstId == listOfEdges->at(j + 1).firstId &&
                        listOfEdges->at(j).secondId > listOfEdges->at(j + 1).secondId) {
                    std::swap(listOfEdges->at(j), listOfEdges->at(j+1));
                }
            }
        }
    }
}