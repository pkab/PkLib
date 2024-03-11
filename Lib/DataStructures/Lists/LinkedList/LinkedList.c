#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(LinkedList* list){
    list->head = NULL;
    list->tail = NULL;
    list->nodes = 0;
}
void ListInsert(LinkedList* list, void* data, u8 type, u64 size){
    Node* newNode = NodeInit(data,type,size);

    if(list->tail==NULL){
        /* Empty List. Set the new Node as both head and tail */
        list->head = newNode;
        list->tail = newNode;
    } else {
        /* Add new node to end of the list */
        newNode->prev = list->tail;
        list->tail = list->tail->next = newNode;
    }
    list->nodes++;
}
void ListInsertFront(LinkedList* list, void* data, u8 type, u64 size){
    Node* newNode = NodeInit(data, type, size);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->nodes++;
}

void ListDelete(LinkedList* list, u64 index){
    if(index >= list->nodes) {
        fprintf(stderr, "LinkedList Error: Index out of bounds\n");
        fflush(stderr);
        return ;
    }

    Node* curr = list->head;

    for(u64 i=0; i<index; i++){
        curr = curr->next;
    }

    if(curr->prev != NULL) curr->prev->next = curr->next;
    else list->head = curr->next; /* If node to be deleted is on head, update head */

    if(curr->next!=NULL) curr->next->prev = curr->prev;
    else list->tail = curr->prev; /* If the node to be deleted is the tail, update the tail */

    NodeFree(curr);
    list->nodes--;
}
void ListDeleteFront(LinkedList* list){
    ListDelete(list,0);
}
void ListDeleteBack(LinkedList* list){
    if(list->tail!=NULL){
        Node* lastNode = list->tail;

        if (lastNode->prev != NULL) {
            lastNode->prev->next = NULL;
            list->tail = lastNode->prev;
        } else {
            list->head = NULL;
            list->tail = NULL;
        }

        free(lastNode->data);
        free(lastNode);
        list->nodes--;
    } else {
        printf("List is Empty\n");
        return ;
    }
}

void ListFree(LinkedList* list){
    Node* curr = list->head;
    Node* nextNode;
    while(curr!=NULL){
        nextNode = curr->next;
        NodeFree(curr);
        curr = nextNode;
    }
    list->head=NULL;
    list->tail=NULL;
    list->nodes=0;
}

void ListPrint(LinkedList* list){
    Node* curr = list->head;
    while(curr!=NULL){
        NodePrint(curr);
        curr=curr->next;
    }
}