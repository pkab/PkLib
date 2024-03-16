#ifndef PKLIB_MINHEAP_H
#define PKLIB_MINHEAP_H

#include <DataStructures/Basic/Node/Node.h>
typedef struct{
    void* arr;
    u8 type;
    u64 height;
    u64 size;
    u64 capacity;
}MinHeap;

void MinHeapInit(MinHeap* heap, u8 type, u64 height);
void MinHeapInsert(MinHeap* heap, void *data);
void MinHeapPrint(MinHeap* heap);
void MinHeapFree(MinHeap* heap);
int MinHeapCompare(void* data1, void *data2, u8 type);
int retHeapType(MinHeap* heap);
void* extractMin(MinHeap *heap);
#endif //PKLIB_MINHEAP_H
