#ifndef PKLIB_BINARYSEARCHTREE_H
#define PKLIB_BINARYSEARCHTREE_H

#include <DataStructures/Basic/Node/TreeNode.h>

typedef struct BST{
    TNode *root;
    u8 type;
    u64 size;
}BSTree;

void BSTInit(BSTree* tree, u8 type, u64 size);
void BSTInsert(BSTree* tree, void* data);
void BSTPrint(BSTree* tree, u8 order);
void BSTSearch(BSTree* tree, void *data);
void BSTDelete(BSTree* tree, void *data);
void BSTFree(BSTree* tree);

#endif //PKLIB_BINARYSEARCHTREE_H
