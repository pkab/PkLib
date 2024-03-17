#include "MaxHeap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void MaxHeapInit(MaxHeap* heap, u8 type, u64 height){
    heap->height = height;
    heap->type = type;
    heap->size = 0;
    heap->capacity = (u64)pow(2,(double)height + 1) - 1;
    heap->arr = malloc(heap->capacity * retMaxHeapType(heap));
    if(heap->arr == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void swapMax(void *a, void *b, int size) {
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

void heapify(MaxHeap *heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int size = retMaxHeapType(heap);
    if (leftChild < heap->size && MaxHeapCompare(&heap->arr[leftChild*size],&heap->arr[largest*size],heap->type) == -1) {
        largest = leftChild;
    }

    if (rightChild < heap->size && MaxHeapCompare(&heap->arr[rightChild*size],&heap->arr[largest*size],heap->type) == -1) {
        largest = rightChild;
    }

    if (largest != index) {
        swapMax(&heap->arr[index*size], &heap->arr[largest*size], retMaxHeapType(heap));
        heapify(heap, largest);
    }
}

void MaxHeapInsert(MaxHeap* heap, void *data){
    if (heap->size == heap->capacity) {
        fprintf(stderr, "Heap is full. Cannot insert more elements.\n");
        return;
    }
    int size = retMaxHeapType(heap);
    int i = heap->size;
    memcpy(heap->arr+i*size,data,size);
    heap->size++;
    // Fix the max-heap property
    int parent = (i-1)/2;
    while (i > 0 && MaxHeapCompare(&heap->arr[i*size], &heap->arr[parent*size],heap->type)==-1 ) {
        swapMax(&heap->arr[i*size], &heap->arr[parent*size], retMaxHeapType(heap));
        i = (i - 1) / 2;
    }

}



void* extractMax(MaxHeap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty. Cannot extract minimum.\n");
        exit(EXIT_FAILURE);
    }

    void* root = &heap->arr[0];
    int size = retMaxHeapType(heap);
    memcpy(heap->arr,heap->arr+(heap->size-1)*size, size);
    heap->size--;
    heapify(heap, 0);

    return root;
}
int retMaxHeapType(MaxHeap* heap){
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
void MaxHeapPrint(MaxHeap* heap){
    printf("MinHeap Array: ");
    int size = retMaxHeapType(heap);
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
void MaxHeapFree(MaxHeap* heap){
    free(heap->arr);
}

int MaxHeapCompare(void* data1, void *data2, u8 type){
    switch (type) {
        case Char:
        case I8:
            if (*(i8*)data1 < *((i8*)data2)) return 1;
            else if(*(i8*)data1 == *(i8*)data2) return 0;
            else return -1;
        case I16:
            if (*(i16*)data1 < *((i16*)data2)) return 1;
            else if(*(i16*)data1 == *(i16*)data2) return 0;
            else return -1;
        case Int:
            if (*(int*)data1 < *((int*)data2)) return 1;
            else if(*(int*)data1 == *(int*)data2) return 0;
            else return -1;
        case I32:
            if (*(i32*)data1 < *((i32*)data2)) return 1;
            else if(*(i32*)data1 == *(i32*)data2) return 0;
            else return -1;
        case I64:
            if (*(i64*)data1 < *((i64*)data2)) return 1;
            else if(*(i64*)data1 == *(i64*)data2) return 0;
            else return -1;
        case U8:
            if(*(u8*)data1 < *(u8*)data2) return 1;
            else if(*(u8*)data1 == *(u8*)data2) return 0;
            else return -1;
        case U16:
            if(*(u16*)data1 < *(u16*)data2) return 1;
            else if(*(u16*)data1 == *(u16*)data2) return 0;
            else return -1;
        case U32:
            if(*(u32*)data1 < *(u32*)data2) return 1;
            else if(*(u32*)data1 == *(u32*)data2) return 0;
            else return -1;
        case U64:
            if(*(u64*)data1 < *(u64*)data2) return 1;
            else if(*(u64*)data1 == *(u64*)data2) return 0;
            else return -1;
        case String:
            if(strcmp(data1,data2)<0) return 1;
            else if(strcmp(data1,data2)==0) return 0;
            else return -1;
    }
}