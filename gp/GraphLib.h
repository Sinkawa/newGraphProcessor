#ifndef ANOTHERONE_GRAPHLIB_H
#define ANOTHERONE_GRAPHLIB_H

#include <vector>
#include <string>
#include <fstream>
#include "Edges.h"
#include "GraphDefines.h"

namespace gp {
    _WEDGELIST getListOfEdgesFromFile(const std::string &pathToFile, bool isOriented = false);
}

#endif
