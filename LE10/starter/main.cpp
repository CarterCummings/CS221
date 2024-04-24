#include "graph.h"

int main() {
    int n = 9;
    Graph g(n);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);

    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);

    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);

    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.print();
    return 0;
}