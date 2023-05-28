#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

struct Vertex
{
};

class Graph
{
private:
    int numVertex;

public:
    Graph();
    ~Graph();

    bool isEmpty();
    bool isDirected();

    void addVertex(Vertex newVertex);
    void addEdge(Vertex vertex1, Vertex vertex2);
};

#endif