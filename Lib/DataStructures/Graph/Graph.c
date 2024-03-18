#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>


Node* createOrPointNode(int v, u8 type, u64 size,void* data, Node* head){
    Node* curr = head;
    while(curr){
        if(!compare(data,curr->data,type)){
            Node * newNode = (Node*) malloc(sizeof(Node));
            newNode->vertex = v;
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }
        curr = curr->next;
    }
    Node* newNode = NodeInit(data, type, size);
    newNode->vertex = v;
    newNode->next=head;
    return newNode;
}
void GraphInit(Graph* G, int nVertices, u8 type, int size){
    G->nVertices = nVertices;
    G->type = type;
    G->objsize = size;
    G->adjList = (Node**)malloc(nVertices * sizeof(Node*));
    int i;
    for(i=0;i<G->nVertices;i++){
        G->adjList[i] = NULL;
    }
}
void addEdge(Graph* g, int src, int dest, void* data){
    Node* newNode;
    newNode = createOrPointNode(dest,g->type,g->objsize,data,g->adjList[src]);
    g->adjList[src] = newNode;
    newNode = createOrPointNode(src, g->type, g->objsize, g->adjList[src]->data, g->adjList[dest]);
    g->adjList[dest] = newNode;
}
void GraphPrint(Graph* G){
    for(int v=0;v<G->nVertices;v++){
        printf("Vertex %d: ",v);
        Node* temp = G->adjList[v];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp=temp->next;
        }
        printf("\n");
        temp = G->adjList[v];
        while(temp){
            NodePrint(temp);
            temp=temp->next;
        }
    }
}
void GraphFree(Graph* G);

