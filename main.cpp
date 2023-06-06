#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph *graph = new Graph();
    Vertex v1(0, 'a'), v2(1, 'b'), v3(2, 'c');

    graph->addVertex(&v1);
    graph->addVertex(&v2);
    graph->addVertex(&v3);

    graph->addEdge(&v1, &v2);
    graph->addEdge(&v2, &v3);

    graph->displayMatrix();

    return 0;
}