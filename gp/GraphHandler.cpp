//
// Created by MarkN on 26.11.2020.
//

#include <climits>
#include "GraphHandler.h"


namespace gp {
    GraphHandler::GraphHandler(Graph *_graph) : graph(_graph) {
        this->bias = 0;
    };

    void GraphHandler::checkBias() {
        this->graph->recalculateBias();
        this->bias = this->graph->getBias();
    }

    std::vector<int> GraphHandler::algDijkstra(int id) {
        checkBias();
        auto *result = new std::vector<int>;
        for (int i = 0; i < this->graph->getListOfNodes()->size(); i++) {
            result->push_back(-1);
        }
        result->at(id + this->bias) = 0;


        auto *listOfEdges = new _WEDGELIST;
        *listOfEdges = *this->graph->getListOfEdges();
        listOfEdges = expandList(listOfEdges);
        listOfEdges = sortList(listOfEdges);

        result = algDijkstraR(findFirst(id, listOfEdges), result, listOfEdges);

        return *result;
    }

    std::vector<int> *GraphHandler::algDijkstraR(int startIndex, std::vector<int> *result, _WEDGELIST *edges) {
        int i = startIndex;
        std::vector<int> nextNodes;
        while (i < edges->size() && edges->at(i).firstId == edges->at(startIndex).firstId) {
            if (!this->graph->getListOfNodes()->at(edges->at(i).secondId + this->bias)->isChecked() &&
                (result->at(edges->at(i).secondId + this->bias) >
                 result->at(edges->at(startIndex).firstId + this->bias) + edges->at(i).weight ||
                 result->at(edges->at(i).secondId + this->bias) == -1)) {
                result->at(edges->at(i).secondId + this->bias) =
                        result->at(edges->at(startIndex).firstId + this->bias) + edges->at(i).weight;
                nextNodes.push_back(edges->at(i).secondId);
            }
            i++;
        }
        this->graph->getListOfNodes()->at(edges->at(startIndex).firstId + this->bias)->setCheck(true);
        if (!nextNodes.empty()) {
            sort(nextNodes, result);

            for (int index = 0; index < nextNodes.size(); index++) {
                if (!this->graph->getListOfNodes()->at(nextNodes.at(index) + this->bias)->isChecked()) {
                    result = algDijkstraR(findFirst(nextNodes.at(index), edges), result, edges);
                }
            }
        }

        return result;
    }

    void GraphHandler::sort(std::vector<int> &idList, std::vector<int> *param) {
        if (idList.empty()) {
            return;
        }

        for (int i = 1; i < idList.size(); i++) {
            for (int j = 0; j < idList.size() - i; j++) {
                if (param->at(idList.at(j) + this->bias) > param->at(idList.at(j + 1) + this->bias)) {
                    std::swap(idList.at(j), idList.at(j + 1));
                }
            }
        }
    }

    int GraphHandler::findFirst(int id, _WEDGELIST *list) {
        for (int i = 0; i < list->size(); i++) {
            if (list->at(i).firstId == id) {
                return i;
            }
        }
        return -1;
    }

    _WEDGELIST *GraphHandler::expandList(_WEDGELIST *list) {
        int size = list->size();
        for (int i = 0; i < size; i++) {
            list->push_back(list->at(i));
            std::swap(list->at(list->size() - 1).firstId, list->at(list->size() - 1).secondId);
        }
        return list;
    }

    _WEDGELIST *GraphHandler::sortList(_WEDGELIST *list) {
        for (int i = 1; i < list->size(); i++) {
            for (int j = 0; j < list->size() - i; j++) {
                if (list->at(j).firstId > list->at(j + 1).firstId) {
                    std::swap(list->at(j), list->at(j + 1));
                } else if (list->at(j).firstId == list->at(j + 1).firstId &&
                           list->at(j).secondId > list->at(j + 1).secondId) {
                    std::swap(list->at(j), list->at(j + 1));
                }
            }
        }
        return list;
    }

    std::vector<int> GraphHandler::algBellmanFord(int id, int endId) {
        checkBias();
        const int size = this->graph->getListOfNodes()->size();
        _WEIGHTMATRIX *weightMatrix = this->graph->getWeightMatrix();
        auto *distance = new std::vector<int>;
        for (int i = 0; i < size; i++) {
            distance->push_back(weightMatrix->at(id + this->bias).at(i));
        }
        distance->at(id + this->bias) = 0;

        for (int k = 0; k < size - 2; k++) {
            for (int v = 0; v < size; v++) {
                if (v != id + this->bias) {
                    for (int u = 0; u < size; u++) {
                        distance->at(v) = min(distance->at(v),
                                              sumWithInfinityCheck(distance->at(u), weightMatrix->at(u).at(v)));
                    }
                }
            }
        }

        int t = endId + this->bias;
        std::stack<int> stack;
        stack.push(t);
        int v = t;
        while (v != id + this->bias) {
            for (int u = 0; u < size; u++) {
                if (distance->at(v) == sumWithInfinityCheck(distance->at(u), weightMatrix->at(u).at(v))) {
                    stack.push(u);
                    v = u;
                }
            }
            int log = 0;
        }

        return stackToVector(stack);
    }

    int GraphHandler::min(int first, int second) {
        if (first <= second) {
            return first;
        } else return second;
    }

    int GraphHandler::sumWithInfinityCheck(int first, int second) {
        long long check = first + second;
        if (first == INT_MAX || second == INT_MAX || check > INT_MAX) {
            return INT_MAX;
        } else return first + second;
    }

    std::vector<int> GraphHandler::EulerianPath(int id) {
        checkBias();
        std::stack<int> helper;
        std::stack<int> result;
        auto *listOfNodes = new _NODELIST;
        *listOfNodes = *this->graph->getListOfNodes();

        helper.push(id + this->bias);

        int v;
        while (!helper.empty()) {
            v = helper.top();
            _NODE *curr = listOfNodes->at(v);
            if (!curr->getListOfAdjacentNodes()->empty()) {
                int u = curr->getListOfAdjacentNodes()->at(0)->getId();
                helper.push(u);
                curr->getListOfAdjacentNodes()->at(0)->removeAdjacentNode(curr);
                curr->removeAdjacentNode(curr->findAdjById(u));
                v = u;
            } else {
                helper.pop();
                result.push(v);
            }
        }


        return stackToVector(result);
    }

    std::vector<int> GraphHandler::stackToVector(std::stack<int> stack) {
        std::vector<int> result(stack.size());

        for (int i = stack.size() - 1; i >= 0; i--) {
            result.at(i) = stack.top();
            stack.pop();
        }

        return result;
    }

    std::vector<int> GraphHandler::HamiltonianPath(int id) {
        checkBias();
        auto *result = new std::stack<int>;

        result->push(id + this->bias);
        this->graph->getListOfNodes()->at(id + this->bias)->setCheck(true);
        result = HamiltonR(1, id + this->bias, result);

        return stackToVector(*result);
    }


    std::stack<int> *GraphHandler::HamiltonR(int id, int startId, std::stack<int> *result) {
        _NODELIST incidenceList = *this->graph->getListOfNodes()->at(result->top())->getListOfAdjacentNodes();
        for (int i = 0; i < incidenceList.size(); i++) {
            if (id == this->graph->getListOfNodes()->size() && incidenceList.at(i)->getId() == startId) {
                result->push(startId);
                return result;
            } else if (!incidenceList.at(i)->isChecked()) {
                result->push(incidenceList.at(i)->getId());
                incidenceList.at(i)->setCheck(true);
                std::stack<int> *temp = HamiltonR(id + 1, startId, result);
                if (temp != nullptr) {
                    return temp;
                };
                incidenceList.at(i)->setCheck(false);
            }
        }
        result->pop();
        return nullptr;
    }


}