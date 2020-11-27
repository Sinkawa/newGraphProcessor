//
// Created by MarkN on 26.11.2020.
//

#include "GraphHandler.h"

namespace gp
{
    GraphHandler::GraphHandler(Graph* _graph) : graph(_graph)
    {
        bias = 0;
    };

    void GraphHandler::recalculateBias()
    {
        bias = graph->getBias();
    }

    std::vector<int> GraphHandler::algDijkstra(int id)
    {
        recalculateBias();
        auto* result = new std::vector<int>;
        for (int i = 0; i < this->graph->getListOfNodes()->size(); i++)
        {
            result->push_back(-1);
        }
        result->at(id + bias) = 0;


        auto* listOfEdges = new std::vector<gp::weightedEdge>;
        *listOfEdges = *this->graph->getListOfEdges();
        listOfEdges = expandList(listOfEdges);
        listOfEdges = sortList(listOfEdges);

        result = algDijkstraR(findFirst(id, listOfEdges), result, listOfEdges);

        return *result;
    }

    std::vector<int>* GraphHandler::algDijkstraR(int startIndex, std::vector<int>* result, std::vector<gp::weightedEdge>* edges)
    {
        int i = startIndex;
        std::vector<int> nextNodes;
        while (i < edges->size() && edges->at(i).firstId == edges->at(startIndex).firstId)
        {
          if (!this->graph->getListOfNodes()->at(edges->at(i).secondId + bias)->isChecked() &&
                  (result->at(edges->at(i).secondId + bias) > result->at(edges->at(startIndex).firstId + bias) + edges->at(i).weight ||
                          result->at(edges->at(i).secondId + bias) == -1))
            {
                result->at(edges->at(i).secondId + bias) = result->at(edges->at(startIndex).firstId + bias) + edges->at(i).weight;
                nextNodes.push_back(edges->at(i).secondId);
            }
            i++;
        }
        this->graph->getListOfNodes()->at(edges->at(startIndex).firstId + bias)->setCheck(true);
        if (!nextNodes.empty())
        {
            sort(nextNodes, result);

            for (int index = 0; index < nextNodes.size(); index++) {
                if (!this->graph->getListOfNodes()->at(nextNodes.at(index) + bias)->isChecked()) {
                    result = algDijkstraR(findFirst(nextNodes.at(index), edges), result, edges);
                }
            }
        }

        return result;
    }

    void GraphHandler::sort(std::vector<int>& idList, std::vector<int>* param)
    {
        if (idList.empty())
        {
            return;
        }

        for (int i = 1; i < idList.size(); i++) {
            for (int j = 0; j < idList.size() - i; j++) {
                if (param->at(idList.at(j) + bias) > param->at(idList.at(j+1)+ bias)) {
                    std::swap(idList.at(j), idList.at(j+1));
                }
            }
        }
    }

    int GraphHandler::findFirst(int id, std::vector<weightedEdge>* list)
    {
        for (int i = 0; i < list->size(); i++)
        {
            if (list->at(i).firstId == id)
            {
                return i;
            }
        }
        return -1;
    }

    std::vector<weightedEdge>* GraphHandler::expandList(std::vector<weightedEdge>* list)
    {
        int size = list->size();
        for (int i = 0; i < size; i++)
        {
            list->push_back(list->at(i));
            std::swap(list->at(list->size()-1).firstId, list->at(list->size()-1).secondId);
        }
        return list;
    }

    std::vector<weightedEdge>* GraphHandler::sortList(std::vector<weightedEdge>* list) {
        for (int i = 1; i < list->size(); i++) {
            for (int j = 0; j < list->size() - i; j++) {
                if (list->at(j).firstId > list->at(j + 1).firstId) {
                    std::swap(list->at(j), list->at(j+1));
                } else if (list->at(j).firstId == list->at(j + 1).firstId &&
                           list->at(j).secondId > list->at(j + 1).secondId) {
                    std::swap(list->at(j), list->at(j+1));
                }
            }
        }
        return list;
    }
}