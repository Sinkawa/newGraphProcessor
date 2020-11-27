//
// Created by MarkN on 26.11.2020.
//

#ifndef ANOTHERONE_GRAPHNODE_H
#define ANOTHERONE_GRAPHNODE_H


#include <vector>

namespace gp
{

    class GraphNode {
        int id;
        bool checkStatus;
        std::vector<GraphNode *> *listOfAdjacentNodes;
    public:

        explicit GraphNode(int id);

        GraphNode(int id, std::vector<GraphNode*> listOfAdjacentNodes);

        int getId() const;

        bool isChecked() const;

        std::vector<GraphNode *> *getListOfAdjacentNodes();

        void setCheck(bool status);

        void addAdjacentNode(GraphNode *adjacentNode);

        bool removeAdjacentNode(GraphNode *adjacentNode);

        ~GraphNode();
    private:

        bool contains(GraphNode *adjacentNode);

        bool removeNode(GraphNode *adjacentNode);
    };

}

#endif //ANOTHERONE_GRAPHNODE_H
