#ifndef PKLIB_STACK_H
#define PKLIB_STACK_H

#include <DataStructures/Lists/LinkedList/LinkedList.h>
typedef struct stck{
    LinkedList list;
} Stack;

void StackInit(Stack* stack);
void StackPush(Stack* stack, void* data, u8 type, uint64_t size);
void StackPop(Stack* stack);
void StackPrint(Stack* stack);
void StackFree(Stack* stack);

#endif
