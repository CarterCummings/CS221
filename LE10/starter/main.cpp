#include "graph.h"

int main() {
    int n = 9;
    Graph g(n);
    g.addEdge(0, 1, 4);
    cout << g.printShortestPath(0,1) << endl;
}