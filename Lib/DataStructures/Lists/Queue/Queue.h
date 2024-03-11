#ifndef PKLIB_QUEUE_H
#define PKLIB_QUEUE_H

#include <DataStructures/Lists/LinkedList/LinkedList.h>

typedef struct qeue{
    LinkedList list;
} Queue;

void QueueInit(Queue* queue);
void Enqueue(Queue* queue, void* data, u8 type, uint64_t size);
void Dequeue(Queue* queue);
void QueuePrint(Queue* queue);
void QueueFree(Queue* queue);

#endif
