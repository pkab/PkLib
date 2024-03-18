#include "MinHeap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void MinHeapInit(MinHeap* heap, u8 type, u64 height){
    heap->height = height;
    heap->type = type;
    heap->size = 0;
    heap->capacity = (u64)pow(2,(double)height + 1) - 1;
    heap->arr = malloc(heap->capacity * retHeapType(heap));
    if(heap->arr == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void swap(void *a, void *b, int size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        // Memory allocation failed
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Copy contents of 'a' to 'temp'
    memcpy(temp,a,size);
    // Copy contents of 'b' to 'a'
    memcpy(a,b,size);
    // Copy contents of 'temp' to 'b'
    memcpy(b,temp,size);
    // Free the temporary memory
    free(temp);
}

void heapifyUp(MinHeap *heap, int index) {
    int parent = (index-1)/2;
    int size = retHeapType(heap);
    while (index > 0 && compare(heap->arr + (index * size), heap->arr + (parent * size), heap->type) > 0) {
        swap(heap->arr+(index*size), heap->arr+(parent*size), size);
        index = parent;
    }
    printf("%d ",*(int*)(heap->arr+(index*size)));
}

void MinHeapInsert(MinHeap* heap, void *data){
    if (heap->size == heap->capacity) {
        fprintf(stderr, "Heap is full. Cannot insert more elements.\n");
        return;
    }
    int size = retHeapType(heap);
    memcpy(heap->arr+heap->size*size,data,size);
    heapifyUp(heap, (int)heap->size);
    heap->size++;
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int size = retHeapType(heap);
    if (leftChild < heap->size && compare(&heap->arr[leftChild * size], &heap->arr[smallest * size], heap->type) == 1) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && compare(&heap->arr[rightChild * size], &heap->arr[smallest * size], heap->type) == 1) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index*size], &heap->arr[smallest*size], retHeapType(heap));
        heapifyDown(heap, smallest);
    }
}

void* extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty. Cannot extract minimum.\n");
        exit(EXIT_FAILURE);
    }

    void* root = &heap->arr[0];
    int size = retHeapType(heap);
    memcpy(heap->arr,heap->arr+(heap->size-1)*size, size);
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}
int retHeapType(MinHeap* heap){
    switch (heap->type) {
        case I8: return sizeof(i8);
        case I16: return sizeof(i16);
        case Int:
        case I32: return sizeof(i32);
        case I64: return sizeof(i64);
        case Float: return sizeof(float);
        case Double: return sizeof(double);
        case Char: return sizeof(char);
        case String: return heap->capacity;
        case U8: return sizeof(u8);
        case U16: return sizeof(u16);
        case U32: return sizeof(u32);
        case U64: return sizeof(u64);
        case Other: return heap->capacity;
        default: return heap->capacity;
    }
}
void MinHeapPrint(MinHeap* heap){
    printf("MinHeap Array: ");
    int size = retHeapType(heap);
    for(int i=0;i< heap->size;i++)
        switch (heap->type) {
            case I8:
            case I16: printf("%d ",*(int*)&heap->arr[i*size]); break;
            case I32: printf("%d ",*(int*)&heap->arr[i*size]); break;
            case Int: printf("%d ",*(int*)&heap->arr[i*size]); break;
            case I64: printf("%ld ",*(i64*)&heap->arr[i*size]); break;
            case U8:
            case U16:
            case U32: printf("%u ",*(u32*)&heap->arr[i*size]); break;
            case U64: printf("%lu ",*(u64*)&heap->arr[i*size]); break;
        }
    printf("\n");
}
void MinHeapFree(MinHeap* heap){
    free(heap->arr);
}