#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* NodeInit(void* data, uint8_t type, uint64_t size){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    size_t dataSize=0;
    switch (type) {
        case Int: dataSize = sizeof(int) * size; break;
        case Float: dataSize = sizeof(float) * size; break;
        case Double: dataSize = sizeof(double) * size; break;
        case Char: dataSize = sizeof(char); break;
        case String: dataSize = sizeof(char) * size; break;
        case _bool: dataSize = sizeof(_Bool) * size; break;
        case Signed8: dataSize = sizeof(i8) * size; break;
        case Signed16: dataSize = sizeof(i16) * size; break;
        case Signed32: dataSize = sizeof(i32) * size; break;
        case Signed64: dataSize = sizeof(i64) * size; break;
        case Unsigned8: dataSize = sizeof(u8) * size; break;
        case Unsigned16: dataSize = sizeof(u16) * size; break;
        case Unsigned32: dataSize = sizeof(u32) * size; break;
        case Unsigned64: dataSize = sizeof(u64) * size; break;
        case _complex: dataSize = sizeof(_Complex) * size; break;

    }
    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed for Node data.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->data,data,dataSize);
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
        case Int:
        case Signed8:
        case Signed16:
        case Signed32:
        case Signed64:
            printf("Pointer: %p, Value: %ld, Type: %u, Size: %lu\n",node->data,*(int64_t*)node->data,node->type,node->size);
            break;
        case Float:
            printf("Pointer: %p, Value: %.2f, Type: %u, Size: %lu\n",node->data,*(float*)node->data,node->type,node->size);
            break;
        case Double:
            printf("Pointer: %p, Value: %.2f, Type: %u, Size: %lu\n",node->data,*(double*)node->data,node->type,node->size);
            break;
        case Char:
            printf("Pointer: %p, Value: %c, Type: %u, Size: %lu\n",node->data,*(char*)node->data,node->type,node->size);
            break;
        case String:
            printf("Pointer: %p, Value: %s, Type: %u, Size: %lu\n",node->data,(char*)node->data,node->type,node->size);
            break;
        default:
            printf("Pointer: %p, Value: %s, Type: %u, Size: %lu\n",node->data,(char*)node->data,node->type,node->size);
            break;
    }
}