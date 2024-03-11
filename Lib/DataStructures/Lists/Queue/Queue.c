#include "Queue.h"
#include <stdio.h>
void QueueInit(Queue* queue) {
    ListInit(&queue->list);
}

void Enqueue(Queue* queue, void* data, u8 type, uint64_t size){
    ListInsert(&queue->list,data, type, size);
}

void Dequeue(Queue* queue) {
    if(queue->list.head)
        ListDeleteFront(&queue->list);
    else{
        fprintf(stderr, "Queue Error: Queue Empty\n");
        exit(EXIT_FAILURE);
    }
}

void QueuePrint(Queue* queue) {
    ListPrint(&queue->list);
}

void QueueFree(Queue* queue) {
    ListFree(&queue->list);
}