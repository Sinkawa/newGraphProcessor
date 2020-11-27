//
// Created by MarkN on 26.11.2020.
//

#ifndef ANOTHERONE_EDGES_H
#define ANOTHERONE_EDGES_H


#include <utility>

namespace gp
{
    class weightedEdge {
    public:
        int firstId;
        int secondId;
        int weight;

        weightedEdge(int firstId, int secondId, int weight) : firstId(firstId), secondId(secondId), weight(weight) {
            if (this->firstId > this->secondId) {
                std::swap(this->firstId, this->secondId);
            }
        }

    };
}

#endif //ANOTHERONE_EDGES_H
