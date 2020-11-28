#ifndef ANOTHERONE_GRAPHNODE_H
#define ANOTHERONE_GRAPHNODE_H

#include <vector>
#include "GraphDefines.h"

namespace gp {

    class GraphNode {
        int id;
        bool checkStatus;
        _NODELIST *listOfAdjacentNodes;
    public:

        explicit GraphNode(int id);

        GraphNode(int id, _NODELIST listOfAdjacentNodes);

        int getId() const;

        _NODE *findAdjById(int id);

        bool isChecked() const;

        _NODELIST *getListOfAdjacentNodes();

        void setCheck(bool status);

        void addAdjacentNode(_NODE *adjacentNode);

        bool removeAdjacentNode(_NODE *adjacentNode);

        ~GraphNode();

    private:

        bool contains(_NODE *adjacentNode);

        bool removeNode(_NODE *adjacentNode);
    };

}

#endif
