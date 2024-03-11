#ifndef PKLIB_BINARYSEARCHTREE_H
#define PKLIB_BINARYSEARCHTREE_H

#include <DataStructures/Basic/Node/TreeNode.h>

typedef struct BST{
    TreeNode *root;
    u8 type;
}BSTree;

void BSTInit(BSTree* tree, u8 type);
void BSTInsert(BSTree* tree, void* data, u8 type, u64 size);
void BSTPrint(BSTree* tree, u8 order);
void BSTSearch(BSTree* tree, void *data);
void BSTDelete(BSTree* tree, void *data);
void BSTFree(BSTree* tree);

#endif //PKLIB_BINARYSEARCHTREE_H
