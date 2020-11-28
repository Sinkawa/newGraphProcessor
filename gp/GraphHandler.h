#ifndef ANOTHERONE_GRAPHHANDLER_H
#define ANOTHERONE_GRAPHHANDLER_H

#include <stack>
#include "GraphNode.h"
#include "Graph.h"

namespace gp {
    class GraphHandler {
        Graph *graph;
        int bias;
    public:
        explicit GraphHandler(Graph *GraphNode);

        std::vector<int> algDijkstra(int id);

        std::vector<int> algBellmanFord(int id, int endId);

        std::vector<int> EulerianPath(int id);

        std::vector<int> HamiltonianPath(int id);

    private:
        void checkBias();

        int min(int first, int second);

        static int findFirst(int id, _WEDGELIST *list);

        void sort(std::vector<int> &idList, std::vector<int> *param);

        int sumWithInfinityCheck(int first, int second);

        static _WEDGELIST *expandList(_WEDGELIST *list);

        static _WEDGELIST *sortList(_WEDGELIST *list);

        std::vector<int> *algDijkstraR(int startIndex, std::vector<int> *result, _WEDGELIST *edges);

        std::vector<int> stackToVector(std::stack<int> stack);

        std::stack<int> *HamiltonR(int id, int startId, std::stack<int> *result);
    };
}

#endif
