#include "Stack.h"
#include <stdio.h>
void StackInit(Stack* stack){
    ListInit(&stack->list);
}
void StackPush(Stack* stack, void* data, u8 type, uint64_t size){
    ListInsertFront(&stack->list, data, type, size);
}
void StackPop(Stack* stack){
    if(stack->list.head) ListDeleteFront(&stack->list);
    else {
        fprintf(stderr, "Stack Error: Stack Empty\n");
        exit(EXIT_FAILURE);
    }
}
void StackPrint(Stack* stack){
    ListPrint(&stack->list);
}
void StackFree(Stack* stack){
    ListFree(&stack->list);
}