#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph *graph = new Graph();
    cout << "Undirected graph initialized\n";

    Vertex v1(0, 'a'), v2(1, 'b'), v3(2, 'c');

    cout << "Adding 3 vertices: (0, 'a'),(1, 'b'), (2, 'c')\n";
    graph->addVertex(&v1);
    graph->addVertex(&v2);
    graph->addVertex(&v3);

    cout << "Adding edges: ('a','b'), ('b','c')\n";
    graph->addEdge(&v1, &v2);
    graph->addEdge(&v2, &v3);

    cout << "\nDisplaying Matrix:\n";
    graph->displayMatrix();

    cout << "\nDegree of 'b': " << graph->degree(&v2) << endl;

    return 0;
}