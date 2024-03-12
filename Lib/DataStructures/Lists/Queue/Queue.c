#include "Queue.h"
#include <stdio.h>

void QueueInit(Queue* queue) {
    ListInit(&queue->list);
}

void Enqueue(Queue* queue, void* data, u8 type, uint64_t size){
    ListInsert(&queue->list,data, type, size);
}

Node* QPeek(Queue* queue){
    return queue->list.head;
}
int isEmpty(Queue* queue){
    if(queue->list.head) return 1;
    return 0;
}
u64 isQNodes(Queue* queue){
    return queue->list.nodes;
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