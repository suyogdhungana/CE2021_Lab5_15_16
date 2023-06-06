#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

struct Vertex
{
    int index;
    char node;

    Vertex() : index(-1) {}
    Vertex(int i, char c) : index(i), node(c) {}
};

class Graph
{
private:
    int numVertices;
    bool **adjMatrix;
    Vertex **vertices;
    bool directed;

public:
    Graph();
    Graph(bool);
    ~Graph();

    bool isEmpty();
    bool isDirected();

    void addVertex(Vertex *newVertex);
    void addEdge(Vertex *vertex1, Vertex *vertex2);

    void removeVertex(Vertex *vertexToRemove);
    void removeEdge(Vertex *vertex1, Vertex *vertex2);

    int numVertex();
    int numEdges();

    int indegree(Vertex *vertex);
    int outdegree(Vertex *vertex);
    int degree(Vertex *vertex);

    // int neighbours(Vertex *vertex);
    bool neighbour(Vertex *vertex1, Vertex *vertex2);

    void displayMatrix();
    void remove(int index);
};

#endif