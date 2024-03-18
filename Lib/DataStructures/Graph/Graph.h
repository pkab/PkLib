#ifndef PKLIB_GRAPH_H
#define PKLIB_GRAPH_H

#include <DataStructures/Basic/Node/Node.h>

typedef struct graph{
    int nVertices;
    u8 type;
    u64 objsize;
    Node ** adjList;
}Graph;

void GraphInit(Graph* G, int nVertices, u8 type, int size);
void GraphFree(Graph* G);
void addEdge(Graph* G, int src, int dest, void* data);
void GraphPrint(Graph* G);
#endif //PKLIB_GRAPH_H
