#ifndef PKLIB_AVLTREE_H
#define PKLIB_AVLTREE_H

#include "DataStructures/Basic/Node/TreeNode.h"

typedef struct avl{
    TNode *root;
    u8 type;
    u64 size;
}AVLTree;

/* Core AVL Tree Functions */
void AVLInit(AVLTree* tree, u8 type, u64 size);
void AVLInsert(AVLTree* tree, void* data);
void AVLDelete(AVLTree* tree, void* data);
void AVLPrint(AVLTree* tree, u8 order);
TNode* AVLSearch(AVLTree* tree, void* data);
void AVLFree(AVLTree* tree);


#endif //PKLIB_AVLTREE_H
