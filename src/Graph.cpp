#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

Graph::Graph()
{
    numVertices = 0;
    directed = false;
    vertices = NULL;
}
Graph::Graph(bool dir) : directed(dir)
{
    numVertices = 0;
    vertices = NULL;
}

Graph::~Graph() {}

bool Graph::isEmpty()
{
    if (numVertices == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Graph::isDirected()
{
    return directed;
}

void Graph::addVertex(Vertex *newVertex)
{
    Vertex **temp = new Vertex *[numVertices + 1];
    for (int i = 0; i < numVertices; i++)
    {
        temp[i] = vertices[i];
    }
    temp[numVertices] = newVertex;
    vertices = temp;

    bool **tempMatrix = new bool *[numVertices + 1];
    for (int i = 0; i < numVertices + 1; i++)
    {
        tempMatrix[i] = new bool[numVertices + 1];
        for (int j = 0; j < numVertices + 1; ++j)
        {
            tempMatrix[i][j] = false;
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            tempMatrix[i][j] = adjMatrix[i][j];
        }
    }
    adjMatrix = tempMatrix;

    ++numVertices;
}

void Graph::addEdge(Vertex *vertex1, Vertex *vertex2)
{
    if (vertex1 == NULL || vertex2 == NULL)
    {
        cout << "Vertex is NULL. Cannot add edge\n";
        return;
    }
    if (adjMatrix[vertex1->index][vertex2->index])
    {
        cout << "Edge already exists\n";
        return;
    }
    if (isDirected())
    {
        adjMatrix[vertex1->index][vertex2->index] = true;
    }
    else
    {
        adjMatrix[vertex1->index][vertex2->index] = true;
        adjMatrix[vertex2->index][vertex1->index] = true;
    }
}

void Graph::removeVertex(Vertex *vertexToRemove)
{
    if (vertexToRemove == NULL)
    {
        cout << "Cannot remove NULL vertex\n";
        return;
    }
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[vertexToRemove->index][i] = false;
        adjMatrix[i][vertexToRemove->index] = false;
    }

    remove(vertexToRemove->index);
}

void Graph::removeEdge(Vertex *vertex1, Vertex *vertex2)
{
    if (vertex1 == NULL || vertex2 == NULL)
    {
        cout << "Invalid vertex. Cannot remove edge.\n";
        return;
    }

    if (!adjMatrix[vertex1->index][vertex2->index])
    {
        cout << "No edge exist!\n";
        return;
    }

    if (isDirected())
    {
        adjMatrix[vertex1->index][vertex2->index] = false;
    }
    else
    {
        adjMatrix[vertex1->index][vertex2->index] = false;
        adjMatrix[vertex2->index][vertex1->index] = false;
    }
}

int Graph::numVertex()
{
    return numVertices;
}

int Graph::numEdges()
{
    int count = 0;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (adjMatrix[i][j])
            {
                count++;
            }
        }
    }
    if (!isDirected())
    {
        count /= 2;
    }
    return count;
}

void Graph::remove(int index)
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = index; j < numVertices - 1; j++)
        {
            adjMatrix[i][j] = adjMatrix[i][j + 1];
        }
    }

    for (int i = index; i < numVertices - 1; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
        }
    }

    for (int i = index; i < numVertices; i++)
    {
        vertices[i] = vertices[i + 1];
    }

    --numVertices;
    delete vertices[numVertices];
}

int Graph::indegree(Vertex *vertex)
{
    int count = 0;
    int index = vertex->index;
    for (int i = 0; i < numVertices; i++)
    {
        if (adjMatrix[index][i])
            ++count;
    }
    return count;
}

int Graph::outdegree(Vertex *vertex)
{
    int count = 0;
    int index = vertex->index;
    for (int i = 0; i < numVertices; i++)
    {
        if (adjMatrix[i][index])
            ++count;
    }
    return count;
}

int Graph::degree(Vertex *vertex)
{
    if (isDirected())
        return indegree(vertex) + outdegree(vertex);
    else
        return indegree(vertex);
}

bool Graph::neighbour(Vertex *vertex1, Vertex *vertex2)
{
    return adjMatrix[vertex1->index][vertex2->index] || adjMatrix[vertex2->index][vertex1->index];
}

void Graph::displayMatrix()
{
    cout << "  ";
    for (int i = 0; i < numVertices; i++)
    {
        cout << vertices[i]->node << " ";
    }
    cout << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << vertices[i]->node << " ";
        for (int j = 0; j < numVertices; j++)
        {
            if (adjMatrix[i][j])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}