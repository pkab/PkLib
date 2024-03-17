#include <DataStructures/Trees/Heap/MaxHeap.h>
#include <stdio.h>

int main() {
    MaxHeap heap;
    MaxHeapInit(&heap,I32,3);
    i32 arr[8] = {3,2,1,5,8,6,7,-2};
    for(int i=0;i<8;i++){
        MaxHeapInsert(&heap,&arr[i]);
    }
    MaxHeapPrint(&heap);
    MaxHeapFree(&heap);
    return 0;
}
