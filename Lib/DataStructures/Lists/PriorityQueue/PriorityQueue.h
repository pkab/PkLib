#ifndef PKLIB_PRIORITYQUEUE_H
#define PKLIB_PRIORITYQUEUE_H

#include <DataStructures/Basic/Node/Node.h>

typedef struct pq{
    Node* front;
    Node* rear;
    u8 type;
}PriorityQueue;

void PQInitFixed(PriorityQueue* pq, u8 type);
void PQInit(PriorityQueue* pq);
int isPQEmpty(PriorityQueue* pq);
void EnPQueueOne(PriorityQueue* pq, void* data, int priority);
void EnPQueue(PriorityQueue* pq, void* data, int priority, u8 type, u64 size);
Node* PQPeek(PriorityQueue* pq);
void* DePQueue(PriorityQueue* pq);
void PQPrint(PriorityQueue* pq);
void PQFree(PriorityQueue* pq);

#endif //PKLIB_PRIORITYQUEUE_H
