#ifndef PKLIB_AVLTREE_H
#define PKLIB_AVLTREE_H

#include <DataStructures/Basic/Node/TreeNode.h>

typedef struct avl{
    TNode *root;
    u8 type;
    u64 size;
}AVLTree;

/* CORE AVL Tree Internal Comparison and Calculation Functions */
int AVLHeight(TNode* N);
int AVLBalance(TNode* N);
int max(int a,int b);
int AVLCompare(void* data1, void* data2, u8 type);
/* Internal Node Operations Functions */
TNode* AVLRotateRight(TNode* y);
TNode* AVLRotateLeft(TNode* x);
TNode* AVLRecusiveInsert(TNode* node, void* data, u8 type, u64 size);
TNode* AVLRecursiveDelete(TNode* node, void* data, u8 type);
void AVLFreeNode(TNode* node);
TNode* AVLSearchNode(TNode* node, void* data, u8 type);
/* Core AVL Tree Functions */
void AVLInit(AVLTree* tree, u8 type, u64 size);
void AVLInsert(AVLTree* tree, void* data);
void AVLDelete(AVLTree* tree, void* data);
void AVLPrint(AVLTree* tree, u8 order);
TNode* AVLSearch(AVLTree* tree, void* data);
void AVLFree(AVLTree* tree);
/* Core AVL Display Functions */
void AVLPreOrder(TNode* root);
void AVLPostOrder(TNode* root);
void AVLInOrder(TNode* root);

#endif //PKLIB_AVLTREE_H
