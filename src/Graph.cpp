#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

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
    bool isDirected = true;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; i++)
            if (adjMatrix[i][j] == adjMatrix[j][i])
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}

void Graph::addVertex(vertex newVertex)
{
    numVertices++;
    adjMatrix[newVertex.index][newVertex.index] = true;
}

void Graph::addEdge(vertex vertex1, vertex vertex2)
{
    adjMatrix[vertex1.index][vertex2.index] = true;
    adjMatrix[vertex2.index][vertex1.index] = true;
}

void Graph::removeVertex(vertex vertexToRemove)
{
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[vertexToRemove.index][i] = false;
        adjMatrix[i][vertexToRemove.index] = false;
    }
}

void Graph::removeEdge(vertex vertex1, vertex vertex2)
{
    adjMatrix[vertex1.index][vertex2.index] = false;
    adjMatrix[vertex2.index][vertex1.index] = false;
}

int Graph::NumVertices()
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