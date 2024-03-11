#ifndef PKLIB_LINKEDLIST_H
#define PKLIB_LINKEDLIST_H
#include <DataStructures/Basic/Node/Node.h>
#include <stdlib.h>
typedef struct LnkLst{
    Node *head;
    Node *tail;
    u64 nodes;
}LinkedList;

void ListInit(LinkedList*);
void ListInsert(LinkedList*, void*, u8, u64);
void ListInsertFront(LinkedList*, void*, u8, u64);
void ListDelete(LinkedList*, u64);
void ListDeleteBack(LinkedList*);
void ListDeleteFront(LinkedList*);
void ListFree(LinkedList*);
void ListPrint(LinkedList*);
#endif