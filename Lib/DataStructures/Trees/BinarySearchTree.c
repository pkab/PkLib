#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(void* data1, void* data2, u8 type);

void BSTInit(BSTree* tree, u8 type){
    tree->root = NULL;
    tree->type = type;
}

TreeNode* RecursiveBSTInsert(TreeNode* curr, void* data, u8 type, u64 size){
    if(curr == NULL) return TreeNodeInit(data,type,size);
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

void BSTInsert(BSTree* tree, void* data, u8 type, u64 size){
    tree->root = RecursiveBSTInsert(tree->root, data, type, size);
}

void inorderTraversal(TreeNode* curr){
    if(curr){
        inorderTraversal(curr->left);
        TreeNodePrint(curr);
        inorderTraversal(curr->right);
    }
}

void preorderTraversal(TreeNode* curr){
    if(curr){
        TreeNodePrint(curr);
        preorderTraversal(curr->left);
        preorderTraversal(curr->right);
    }
}

void postOrderTraversal(TreeNode* curr){
    if(curr){
        postOrderTraversal(curr->left);
        postOrderTraversal(curr->right);
        TreeNodePrint(curr);
    }
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
TreeNode *searchNode(TreeNode* root, void* data, u8 type){
    if(root == NULL || compare(data,root->data,type) == 0)
        return root;

    if(compare(data,root->data,type) == 1) return searchNode(root->left,data,type);

    return searchNode(root->right,data,type);
}
void BSTSearch(BSTree* tree, void *data){
    TreeNode *Node = searchNode(tree->root,data,tree->type);
    if(Node)
        TreeNodePrint(Node);
    else printf("Node not found");
    printf("\n");
}
void freeBSTNode(TreeNode* node){
    if(node != NULL){
        freeBSTNode(node->left);
        freeBSTNode(node->right);
        TreeNodeFree(node);
    }
}
void BSTFree(BSTree* tree){
    freeBSTNode(tree->root);
}
int compare(void* data1, void* data2, u8 type){
    switch (type) {
        case Char:
        case I8:
            if (*(i8*)data1 < *((i8*)data2)) return 1;
            else if(*(i8*)data1 == *(i8*)data2) return 0;
            else return -1;
        case I16:
            if (*(i16*)data1 < *((i16*)data2)) return 1;
            else if(*(i16*)data1 == *(i16*)data2) return 0;
            else return -1;
        case Int:
        case I32:
            if (*(i32*)data1 < *((i32*)data2)) return 1;
            else if(*(i32*)data1 == *(i32*)data2) return 0;
            else return -1;
        case I64:
//            printf("%ld %ld\n",*((int*)data1),*((i64*)data2));
            if (*(i64*)data1 < *((i64*)data2)) return 1;
            else if(*(i64*)data1 == *(i64*)data2) return 0;
            else return -1;
        case U8:
            if(*(u8*)data1 < *(u8*)data2) return 1;
            else if(*(u8*)data1 == *(u8*)data2) return 0;
            else return -1;
        case U16:
            if(*(u16*)data1 < *(u16*)data2) return 1;
            else if(*(u16*)data1 == *(u16*)data2) return 0;
            else return -1;
        case U32:
            if(*(u32*)data1 < *(u32*)data2) return 1;
            else if(*(u32*)data1 == *(u32*)data2) return 0;
            else return -1;
        case U64:
            if(*(u64*)data1 < *(u64*)data2) return 1;
            else if(*(u64*)data1 == *(u64*)data2) return 0;
            else return -1;
        case String:
            if(strcmp(data1,data2)<0) return 1;
            else if(strcmp(data1,data2)==0) return 0;
            else return -1;
    }
}
static TreeNode* findMinNode(TreeNode * node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static TreeNode* deleteBSTNodeRecursive(TreeNode* root, void* data, u8 type) {
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
            TreeNode * temp = root->right;
            free(root->data);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode * temp = root->left;
            free(root->data);
            free(root);
            return temp;
        }

        // Node with two children
        TreeNode * temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteBSTNodeRecursive(root->right, temp->data, type);
    }

    return root;
}

void BSTDelete(BSTree* tree, void* data) {
    tree->root = deleteBSTNodeRecursive(tree->root, data, tree->type);
}