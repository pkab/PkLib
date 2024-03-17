#include <DataStructures/Trees/Heap/MinHeap.h>
#include <stdio.h>

int main() {
    MinHeap heap;
    MinHeapInit(&heap,I32,3);
    i32 arr[8] = {3,2,1,5,8,6,7,-2};
    for(int i=0;i<8;i++){
        MinHeapInsert(&heap,&arr[i]);
    }
    MinHeapPrint(&heap);
    MinHeapFree(&heap);
    return 0;
}
