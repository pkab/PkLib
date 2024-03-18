#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>

void freeBSTNode(TNode* node);
void inorderTraversal(TNode* curr);
void preorderTraversal(TNode* curr);
void postOrderTraversal(TNode* curr);
TNode* findMinNode(TNode * node);
TNode* deleteBSTNodeRecursive(TNode* root, void* data, u8 type);
TNode* searchNode(TNode* root, void* data, u8 type);

TNode* RecursiveBSTInsert(TNode* curr, void* data, u8 type, u64 size){
    if(curr == NULL) return TNodeInit(data, type, size);
    else {
        if(compare(data,curr->data,type)==1) {
            curr->left = RecursiveBSTInsert(curr->left, data, type,size);
        }
        else if(compare(data,curr->data,type)==-1){
            curr->right = RecursiveBSTInsert(curr->right, data, type,size);
        }

    }
    return curr;
}

void BSTInit(BSTree* tree, u8 type, u64 size){
    tree->root = NULL;
    tree->type = type;
    tree->size = size;
}

void BSTInsert(BSTree* tree, void* data){
    tree->root = RecursiveBSTInsert(tree->root, data, tree->type, tree->size);
}


void BSTPrint(BSTree* tree, u8 order){
    switch (order) {
        case 0: inorderTraversal(tree->root); break;
        case 1: preorderTraversal(tree->root); break;
        case 2: postOrderTraversal(tree->root); break;
        default: break;
    }
    printf("\n");
}

void BSTSearch(BSTree* tree, void *data){
    TNode *Node = searchNode(tree->root, data, tree->type);
    if(Node)
        TNodePrint(Node);
    else printf("Node not found");
    printf("\n");
}

void BSTDelete(BSTree* tree, void* data) {
    tree->root = deleteBSTNodeRecursive(tree->root, data, tree->type);
}

void BSTFree(BSTree* tree){
    freeBSTNode(tree->root);
}

void inorderTraversal(TNode* curr){
    if(curr){
        inorderTraversal(curr->left);
        TNodePrint(curr);
        inorderTraversal(curr->right);
    }
}

void preorderTraversal(TNode* curr){
    if(curr){
        TNodePrint(curr);
        preorderTraversal(curr->left);
        preorderTraversal(curr->right);
    }
}

void postOrderTraversal(TNode* curr){
    if(curr){
        postOrderTraversal(curr->left);
        postOrderTraversal(curr->right);
        TNodePrint(curr);
    }
}

void freeBSTNode(TNode* node){
    if(node != NULL){
        freeBSTNode(node->left);
        freeBSTNode(node->right);
        TNodeFree(node);
    }
}

TNode *searchNode(TNode* root, void* data, u8 type){
    if(root == NULL || compare(data,root->data,type) == 0)
        return root;

    if(compare(data,root->data,type) == 1) return searchNode(root->left,data,type);

    return searchNode(root->right,data,type);
}

TNode* deleteBSTNodeRecursive(TNode* root, void* data, u8 type) {
    if (root == NULL) {
        return root;
    }

    if (compare(data,root->data,type) ==1) {
        root->left = deleteBSTNodeRecursive(root->left, data, type);
    } else if (compare(data,root->data,type) ==-1) {
        root->right = deleteBSTNodeRecursive(root->right, data, type);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TNode * temp = root->right;
            TNodeFree(root);
            return temp;
        } else if (root->right == NULL) {
            TNode * temp = root->left;
            TNodeFree(root);
            return temp;
        }

        // Node with two children
        TNode * temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteBSTNodeRecursive(root->right, temp->data, type);
    }

    return root;
}

TNode* findMinNode(TNode * node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
