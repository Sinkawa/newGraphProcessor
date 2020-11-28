//
// Created by sinkawa on 28.11.2020.
//

#include "GraphLib.h"

namespace gp {
    _WEDGELIST getListOfEdgesFromFile(const std::string &pathToFile, bool isOriented) {
        std::ifstream file(pathToFile);
        _WEDGELIST list;

        if (!file.is_open()) {
            return list;
        }

        while (!file.eof()) {
            int firstId, secondId, weight;
            file >> firstId >> secondId >> weight;
            list.emplace_back(firstId, secondId, weight, isOriented);
        }

        file.close();

        return list;
    }
}