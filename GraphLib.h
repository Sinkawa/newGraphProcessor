//
// Created by MarkN on 27.11.2020.
//

#ifndef ANOTHERONE_GRAPHLIB_H
#define ANOTHERONE_GRAPHLIB_H

#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include "Edges.h"

namespace gp
{

    std::vector<gp::weightedEdge> getListOfEdgesFromFile(std::string pathToFile = "data.txt")
    {
        std::ifstream file(pathToFile);
        std::vector<gp::weightedEdge> list;

        if (!file.is_open())
        {
            return list;
        }

        while (!file.eof())
        {
            int firstId, secondId, weight;
            file >> firstId >> secondId >> weight;
            list.emplace_back(firstId, secondId, weight);
        }

        file.close();

        return list;
    }
}

#endif //ANOTHERONE_GRAPHLIB_H
