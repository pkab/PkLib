#include "TreeNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TNode* TNodeInit(void* data, u8 type, u64 size){
    TNode* newNode = malloc(sizeof(TNode));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->height=0;
    size_t dataSize;
    switch (type) {
        case Int: dataSize = sizeof(int); break;
        case Float: dataSize = sizeof(float); break;
        case Double: dataSize = sizeof(double); break;
        case Char: dataSize = sizeof(char); break;
        case String: dataSize = sizeof(char) * size; break;
        case _bool: dataSize = sizeof(_Bool); break;
        case I8: dataSize = sizeof(i8); break;
        case I16: dataSize = sizeof(i16); break;
        case I32: dataSize = sizeof(i32); break;
        case I64: dataSize = sizeof(i64); break;
        case U8: dataSize = sizeof(u8); break;
        case U16: dataSize = sizeof(u16); break;
        case U32: dataSize = sizeof(u32); break;
        case U64: dataSize = sizeof(u64); break;
        case _complex: dataSize = sizeof(_Complex); break;
        default: dataSize = size; break;

    }
    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed for Node data.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    memcpy(newNode->data,data,size);
    newNode->type = type;
    newNode->size = size;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void TNodeFree(TNode* node){
    free(node->data);
    free(node);
}
void TreeNodePrintVal(TNode* node){
    switch (node->type) {
        case Int:
        case I8:
        case I16:
        case I32:
        case I64:
            printf("%ld ",*(i64*)node->data);
            break;
        case U8:
        case U16:
        case U32:
        case U64:
            printf("%lu ",*(u64*)node->data);
            break;
        case Float:
            printf("%.2f ",*(float*)node->data);
            break;
        case Double:
            printf("%.2f ",*(double*)node->data);
            break;
        case Char:
            printf("%c ",*(char*)node->data);
            break;
        case String:
            printf("%s ",(char*)node->data);
            break;
        default:
            printf("%s ",(char*)node->data);
            break;
    }
}
void TNodePrint(TNode* node){
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