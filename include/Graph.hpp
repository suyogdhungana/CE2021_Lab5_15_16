#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

struct Vertex
{
    int data;
    Vertex *head;
    Vertex *tail;
    Vertex *prev;
    Vertex *next;
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

    int numVertices();
    int numEdges();

    int indegree(Vertex vertex);
    int outdegree(Vertex vertex);
    int degree(Vertex vertex);

    int neighbours(Vertex vertex);
    bool neighbour(Vertex vertex1, Vertex vertex2);
};

#endif