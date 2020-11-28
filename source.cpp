#include <iostream>
#include "gp/GraphProcessor.h"


void print(std::vector<int> list) {
    std::cout << "path: ";
    for (int i = list.size() - 1; i >= 0; i--) {
        std::cout << list.at(i) + 1 << " ";
    }
    std::cout << std::endl;
}

void printD(std::vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        std::cout << "[" << i << "] " << list.at(i) << std::endl;
    }
}

int main() {
    int mode = 0;
    std::cout << "0 - Dijkstra; 1 - Bellman-Ford; 2 - Eulerian Path; 3 - Hamiltonian Path; " << std::endl
              << "Choose program: ";
    std::cin >> mode;

    bool isOriented = false;
    if (mode == 1) {
        isOriented = true;
    }

    std::string fileName[] = {
            "dataDijkstra", "dataBellmanFord",
            "dataEuler", "dataHamilton"
    };

    auto *graph = new gp::Graph(isOriented);
    gp::GraphHandler graphHandler(graph);

    auto *list = new _WEDGELIST;
    *list = gp::getListOfEdgesFromFile(fileName[mode] + ".txt", isOriented);
    if (list->empty()) {
        return -404;
    }
    graph->setListOfEdges(*list);
    delete list;

    graph->createGraphByEdges();

    int id;
    std::cout << "Enter start node: ";
    std::cin >> id;

    std::vector<int> result;
    switch (mode) {
        case 0:
            result = graphHandler.algDijkstra(id);
            break;
        case 1:
            int endId;
            std::cout << "Enter end node: ";
            std::cin >> endId;
            result = graphHandler.algBellmanFord(id, endId);
            break;
        case 2:
            result = graphHandler.EulerianPath(id);
            break;
        case 3:
            result = graphHandler.HamiltonianPath(id);
            break;
        default:
            return -103;
    }

    if (mode == 0) {
        printD(result);
    } else
        print(result);

    return 0;
}