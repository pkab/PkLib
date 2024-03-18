#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <DataStructures/Dictionary/Entry.h>
Node* NodeInit(void* data, uint8_t type, uint64_t size){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->priority = 0;
    size_t dataSize=0;
    switch (type) {
        case Int: dataSize = sizeof(int) * size; break;
        case Float: dataSize = sizeof(float) * size; break;
        case Double: dataSize = sizeof(double) * size; break;
        case Char: dataSize = sizeof(char); break;
        case String: dataSize = sizeof(char) * size; break;
        case _bool: dataSize = sizeof(_Bool) * size; break;
        case I8: dataSize = sizeof(i8) * size; break;
        case I16: dataSize = sizeof(i16) * size; break;
        case I32: dataSize = sizeof(i32) * size; break;
        case I64: dataSize = sizeof(i64) * size; break;
        case U8: dataSize = sizeof(u8) * size; break;
        case U16: dataSize = sizeof(u16) * size; break;
        case U32: dataSize = sizeof(u32) * size; break;
        case U64: dataSize = sizeof(u64) * size; break;
        case _complex: dataSize = sizeof(_Complex double) * size; break;
        case Other: dataSize = size; break;
        default: dataSize = size; break;

    }

    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed for Node data.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->data, data, dataSize);
    newNode->type = type;
    newNode->size = size;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void NodeFree(Node* node){
    free(node->data);
    free(node);
}

void NodePrint(Node* node){
    switch (node->type) {
        case I8:
            printf("Pointer: %p, Value: %d, Type: int8, Size: %lu\n",node->data,*(i8*)node->data,node->size);
            break;
        case I16:
            printf("Pointer: %p, Value: %d, Type: int16, Size: %lu\n",node->data,*(i16*)node->data,node->size);
            break;
        case Int:
        case I32:
            printf("Pointer: %p, Value: %d, Type: int32, Size: %lu\n",node->data,*(i32*)node->data,node->size);
            break;
        case I64:
            printf("Pointer: %p, Value: %ld, Type: int64, Size: %lu\n",node->data,*(i64*)node->data,node->size);
            break;
        case Float:
            printf("Pointer: %p, Value: %.2f, Type: float, Size: %lu\n",node->data,*(float*)node->data,node->size);
            break;
        case Double:
            printf("Pointer: %p, Value: %.2f, Type: double, Size: %lu\n",node->data,*(double*)node->data,node->size);
            break;
        case Char:
            printf("Pointer: %p, Value: %c, Type: char, Size: %lu\n",node->data,*(char*)node->data,node->size);
            break;
        case String:
            printf("Pointer: %p, Value: %s, Type: String, Size: %lu\n",node->data,(char*)node->data,node->size);
            break;
        case U8:
            printf("Pointer: %p, Value: %u, Type: U8, Size: %lu\n",node->data,*(u8*)node->data,node->size);
            break;
        case U16:
            printf("Pointer: %p, Value: %u, Type: U16, Size: %lu\n",node->data,*(u16*)node->data,node->size);
            break;
        case U32:
            printf("Pointer: %p, Value: %u, Type: U32, Size: %lu\n",node->data,*(u32*)node->data,node->size);
            break;
        case U64:
            printf("Pointer: %p, Value: %lu, Type: U64, Size: %lu\n",node->data,*(u64*)node->data,node->size);
            break;
        case Other:
            printf("Pointer: %p, Type: Other, Size: %lu\n",node->data,node->size);
            break;
        default:
            printf("Pointer: %p, Value: %s, Type: %u, Size: %lu\n",node->data,(char*)node->data,node->type,node->size);
            break;
    }
}

void NodePriorityPrint(Node* node){
    switch (node->type) {
        case I8:
            printf("Pointer: %p, Value: %d, Priority: %d, Type: int8, Size: %lu\n",
                   node->data,*(i8*)node->data,node->priority,node->size);
            break;
        case I16:
            printf("Pointer: %p, Value: %d, Priority: %d, Type: int16, Size: %lu\n",
                   node->data,*(i16*)node->data,node->priority,node->size);
            break;
        case Int:
        case I32:
            printf("Pointer: %p, Value: %d, Priority: %d, Type: int32, Size: %lu\n",
                   node->data,*(i32*)node->data,node->priority,node->size);
            break;
        case I64:
            printf("Pointer: %p, Value: %ld, Priority: %d, Type: int64, Size: %lu\n",
                   node->data,*(i64*)node->data,node->priority,node->size);
            break;
        case Float:
            printf("Pointer: %p, Value: %.2f, Priority: %d, Type: float, Size: %lu\n",
                   node->data,*(float*)node->data,node->priority,node->size);
            break;
        case Double:
            printf("Pointer: %p, Value: %.2f, Priority: %d, Type: double, Size: %lu\n",
                   node->data,*(double*)node->data,node->priority,node->size);
            break;
        case Char:
            printf("Pointer: %p, Value: %c, Priority: %d, Type: char, Size: %lu\n",
                   node->data,*(char*)node->data,node->priority,node->size);
            break;
        case String:
            printf("Pointer: %p, Value: %s, Priority: %d, Type: String, Size: %lu\n",
                   node->data,(char*)node->data,node->priority,node->size);
            break;
        case U8:
            printf("Pointer: %p, Value: %u, Priority: %d, Type: U8, Size: %lu\n",
                   node->data,*(u8*)node->data,node->priority,node->size);
            break;
        case U16:
            printf("Pointer: %p, Value: %u, Priority: %d, Type: U16, Size: %lu\n",
                   node->data,*(u16*)node->data,node->priority,node->size);
            break;
        case U32:
            printf("Pointer: %p, Value: %u, Priority: %d, Type: U32, Size: %lu\n",
                   node->data,*(u32*)node->data,node->priority,node->size);
            break;
        case U64:
            printf("Pointer: %p, Value: %lu, Priority: %d, Type: U64, Size: %lu\n",
                   node->data,*(u64*)node->data,node->priority,node->size);
            break;
        case Other:
            printf("Pointer: %p, Priority: %d, Type: Other, Size: %lu\n",
                   node->data,node->priority,node->size);
            break;
        default:
            printf("Pointer: %p, Value: %s, Priority: %d, Type: %u, Size: %lu\n",
                   node->data,(char*)node->data,node->type,node->priority,node->size);
            break;
    }
}
u64 retSizeType(Node* node){
    switch (node->type) {
        case I8: return sizeof(i8);
        case I16: return sizeof(i16);
        case Int:
        case I32: return sizeof(i32);
        case I64: return sizeof(i64);
        case Float: return sizeof(float);
        case Double: return sizeof(double);
        case Char: return sizeof(char);
        case String: return node->size;
        case U8: return sizeof(u8);
        case U16: return sizeof(u16);
        case U32: return sizeof(u32);
        case U64: return sizeof(u64);
        case Other: return node->size;
        default: return node->size;
    }
}