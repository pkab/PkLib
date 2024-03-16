#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PQInitFixed(PriorityQueue* pq, u8 type){
    pq->front = pq->rear =NULL;
    pq->type = type;
}
void PQInit(PriorityQueue* pq){
    pq->front = pq->rear = NULL;
    pq->type=0;
}
int isPQEmpty(PriorityQueue* pq){
    return (pq->front==NULL);
}
void EnPQueue(PriorityQueue* pq, void* data, int priority, u8 type, u64 size){
    Node* newNode = NodeInit(data,type,size);
    newNode->priority = priority;

    if(isPQEmpty(pq)){
        pq->front = pq->rear = newNode;
    } else if(priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = pq->front->prev = newNode;
    } else {
        Node* curr = pq->front;
        while(curr->next && curr->next->priority <= priority){
            curr = curr->next;
        }

        newNode->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = newNode;
        } else {
            pq->rear = newNode;
        }
        newNode->prev = curr;
        curr->next = newNode;
    }
}
void EnPQueueOne(PriorityQueue* pq, void* data, int priority){
    EnPQueue(pq,data,priority,pq->type,1);
}
Node* PQPeek(PriorityQueue* pq){
    return pq->front;
}
void* DePQueue(PriorityQueue* pq){
    if(isPQEmpty(pq)){
        fprintf(stderr, "Priority Queue is Empty \n");
        exit(EXIT_FAILURE);
    }

    Node* frontNode = pq->front;
    void* data = malloc(sizeof(retSizeType(frontNode)));
    memcpy(data,frontNode->data, retSizeType(frontNode));

    pq->front = frontNode->next;
    if(pq->front) pq->front->prev = NULL;
    else pq->rear = NULL;

    NodeFree(frontNode);
    return data;
}
void PQPrint(PriorityQueue* pq){
    Node* curr = pq->front;
    while (curr){
        NodePriorityPrint(curr);
        curr = curr->next;
    }
}
void PQFree(PriorityQueue* pq){
    while(isPQEmpty(pq)){
        DePQueue(pq);
    }
}
