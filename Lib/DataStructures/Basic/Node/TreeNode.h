#ifndef PKLIB_TREENODE_H
#define PKLIB_TREENODE_H

#include <DataStructures/Basic/Comparator/Comparator.h>

typedef struct Tnode{
    void *data; /* void pointer for any Data */
    uint8_t type; /* void Data type */
    uint64_t size; /* Size */
    int height;
    struct Tnode* left; /* Next node prev */
    struct Tnode* right; /* previous node */
}TNode;

TNode* TNodeInit(void* data, u8 type, u64 size);
void TNodeFree(TNode* node);
void TNodePrint(TNode* node);
void TreeNodePrintVal(TNode* node);
#endif
