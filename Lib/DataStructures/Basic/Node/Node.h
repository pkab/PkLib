#ifndef PKLIB_NODE_H
#define PKLIB_NODE_H
#include <DataStructures/Basic/Comparator/Comparator.h>
/*
 * Node Data Structure
 * Data can be of any type
 * Defined by type of data
 * size defines the size of Data
 */
typedef struct NODE{
    int vertex; /* Vertex to be used for graph*/
    void *data; /* void pointer for any Data */
    uint8_t type; /* void Data type */
    uint64_t size; /* Size */
    int priority; /* To be used for Priority Queue */
    struct NODE* next; /* Next node prev */
    struct NODE* prev; /* previous node */
}Node;

Node* NodeInit(void* , uint8_t, uint64_t);
void NodeFree(Node*);
void NodePrint(Node*);
void NodePriorityPrint(Node*);
u64 retSizeType(Node*);
#endif //PKLIB_NODE_H
