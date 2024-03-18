#ifndef PKLIB_MAXHEAP_H
#define PKLIB_MAXHEAP_H

#include <DataStructures/Basic/Node/Node.h>

typedef struct{
    void* arr;
    u8 type;
    u64 height;
    u64 size;
    u64 capacity;
}MaxHeap;

void MaxHeapInit(MaxHeap* heap, u8 type, u64 height);
void MaxHeapInsert(MaxHeap* heap, void *data);
void MaxHeapPrint(MaxHeap* heap);
void MaxHeapFree(MaxHeap* heap);
int retMaxHeapType(MaxHeap* heap);
void* extractMax(MaxHeap *heap);

#endif //PKLIB_MAXHEAP_H
