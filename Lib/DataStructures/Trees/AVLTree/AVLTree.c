#include "AVLTree.h"
#include <stdio.h>
#include <string.h>

/* CORE AVL Tree Internal Comparison and Calculation Functions */
int AVLHeight(TNode* N);
int AVLBalance(TNode* N);
int max(int a,int b);
/* Internal Node Operations Functions */
TNode* AVLRotateRight(TNode* y);
TNode* AVLRotateLeft(TNode* x);
TNode* AVLRecusiveInsert(TNode* node, void* data, u8 type, u64 size);
TNode* AVLRecursiveDelete(TNode* node, void* data, u8 type);
void AVLFreeNode(TNode* node);
TNode* AVLSearchNode(TNode* node, void* data, u8 type);
/* Core AVL Display Functions */
void AVLPreOrder(TNode* root);
void AVLPostOrder(TNode* root);
void AVLInOrder(TNode* root);
/*
 * --------------------- CORE AVL Tree Functions START --------------------- *
 */

/* Initialize AVL Tree */
void AVLInit(AVLTree* tree, u8 type, u64 size){
    tree->root=NULL;
    tree->type=type;
    tree->size=size;
}

/* Insert Data into AVL Tree */
void AVLInsert(AVLTree* tree, void* data){
    tree->root = AVLRecusiveInsert(tree->root, data, tree->type, tree->size);
}

/* Delete Node from AVL Tree */
void AVLDelete(AVLTree* tree, void* data){
    AVLRecursiveDelete( tree->root, data, tree->type);
}

/* Print AVL Tree order wise */
void AVLPrint(AVLTree* tree, u8 order){
    switch (order) {
        case 0: AVLInOrder(tree->root); break;
        case 1: AVLPreOrder(tree->root); break;
        case 2: AVLPostOrder(tree->root); break;
        default: break;
    }
    printf("\n");
}

/* Search for Node in the AVL Tree */
TNode* AVLSearch(AVLTree* tree, void* data){
    TNode *node = AVLSearchNode(tree->root, data, tree->type);
    if(node) TNodePrint(node);
    else printf("Node not found\n");
    return node;
}

/* Free the AVL Tree After Use */
void AVLFree(AVLTree* tree){
    AVLFreeNode(tree->root);
}
/*
 * --------------------- CORE AVL Tree Functions END ----------------------- *
 */

/*
 * --------------------- Core AVL Display Functions START --------------------- *
 */

/* Display in Pre Order Tree */
void AVLPreOrder(TNode* root){
    if(root){
        TNodePrint(root);
        AVLPreOrder(root->left);
        AVLPreOrder(root->right);
    }
}

/* Display in Post Order Tree */
void AVLPostOrder(TNode* root){
    if(root){
        AVLPostOrder(root->left);
        AVLPostOrder(root->right);
        TNodePrint(root);
    }
}

/* Display in In Order Tree */
void AVLInOrder(TNode* root){
    if(root){
        AVLInOrder(root->left);
        TNodePrint(root);
        AVLInOrder(root->right);
    }
}
/*
 * --------------------- Core AVL Display Functions END ----------------------- *
 */

/*
 * --------------------- CORE AVL Tree Internal Node Functions START --------------------- *
 */

/* A utility function to right rotate subtree rooted with y */
TNode* AVLRotateRight(TNode* y){
    TNode *x = y->left;
    TNode *T2 = x->right;

    /* Perform rotation */
    x->right = y;
    y->left = T2;

    /* Update heights */
    y->height = max(AVLHeight(y->left), AVLHeight(y->right)) + 1;

    x->height = max(AVLHeight(x->left), AVLHeight(x->right)) + 1;

    /* Return new root */
    return x;
}

/* A utility function to left rotate subtree rooted with x */
TNode* AVLRotateLeft(TNode* x){
    TNode *y = x->right;
    TNode *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;

    /* Update heights */
    x->height = max(AVLHeight(x->left), AVLHeight(x->right)) + 1;

    y->height = max(AVLHeight(y->left), AVLHeight(y->right)) + 1;

    /* Return new root */
    return y;
}

/* Recursively Insert Data and Balance it while inserting node into tree */
TNode* AVLRecusiveInsert(TNode* node, void* data, u8 type, u64 size){

    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return TNodeInit(data, type, size);

    if (compare(data, node->data, node->type) == 1)
        node->left  = AVLRecusiveInsert(node->left, data, type, size);
    else if (compare(data, node->data, node->type) == -1)
        node->right = AVLRecusiveInsert(node->right, data, type, size);
    else /* Equal keys are not allowed in BST */
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(AVLHeight(node->left), AVLHeight(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = AVLBalance(node);

    /*
     * If this node becomes unbalanced, then
     * there are 4 cases
     */

    /* Left Left (LL) Case */
    if (balance > 1 && (compare(data, node->left->data, node->type) == 1))
        return AVLRotateRight(node);

    /* Right Right (RR) Case */
    if (balance < -1 && (compare(data, node->right->data, node->type) == -1))
        return AVLRotateLeft(node);

    /* Left Right (LR) Case */
    if (balance > 1 && (compare(data, node->left->data, node->type) == -1))
    {
        node->left =  AVLRotateLeft(node->left);
        return AVLRotateRight(node);
    }

    /* Right Left (RL) Case */
    if (balance < -1 && (compare(data, node->right->data, node->type) == 1))
    {
        node->right = AVLRotateRight(node->right);
        return AVLRotateLeft(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Find the minNode of BST by traversing left */
static TNode* findMinNode(TNode * node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/* Delete Node by searching it recursively */
TNode* AVLRecursiveDelete(TNode* root, void* data, u8 type){
    if (root == NULL) {
        return root;
    }

    if (compare(data, root->data, type) == 1) {
        root->left = AVLRecursiveDelete(root->left, data, type);
    } else if (compare(data, root->data, type) == -1) {
        root->right = AVLRecursiveDelete(root->right, data, type);
    } else {
        /* Node with only one child or no child */
        if (root->left == NULL) {
            TNode * temp = root->right;
            TNodeFree(root);
            return temp;
        } else if (root->right == NULL) {
            TNode * temp = root->left;
            TNodeFree(root);
            return temp;
        }

        /* Node with two children */
        TNode * temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = AVLRecursiveDelete(root->right, temp->data, type);
    }


    if(!root) return root;

    /* STEP 2: UPDATE HEIGHT OF THE CURRENT NODE */
    root->height = 1 + max(AVLHeight(root->left), AVLHeight(root->right));

    /*
     * STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
     * check whether this node became unbalanced)
     */
    int balance = AVLBalance(root);

    /*
     * If this node becomes unbalanced, then
     * there are 4 cases
     */

    /* Left Left (LL) Case */
    if (balance > 1 && AVLBalance(root->left) >= 0) return AVLRotateRight(root);

    /* Left Right (LR) Case */
    if (balance > 1 && AVLBalance(root->left) < 0){
        root->left =  AVLRotateLeft(root->left);
        return AVLRotateRight(root);
    }

    /* Right Right (RR) Case */
    if (balance < -1 && AVLBalance(root->right) <= 0) return AVLRotateLeft(root);

    /* Right Left (RL) Case */
    if (balance < -1 && AVLBalance(root->right) > 0){
        root->right = AVLRotateRight(root->right);
        return AVLRotateLeft(root);
    }

    return root;
}

/* Internal Search for Nodes */
TNode* AVLSearchNode(TNode* root, void* data, u8 type){
    if(root == NULL || compare(data, root->data, type) == 0)
        return root;

    if(compare(data,root->data,type) == 1) return AVLSearchNode(root->left,data,type);

    return AVLSearchNode(root->right,data,type);
}

/* Internal AVL Tree Function to Free the Data Node Wise */
void AVLFreeNode(TNode* node){
    if(node){
        AVLFreeNode(node->left);
        AVLFreeNode(node->right);
        TNodeFree(node);
    }
}
/*
 * --------------------- CORE AVL Tree Internal Node Functions END ----------------------- *
 */

/*
 * --------------------- CORE AVL Tree Internal Comparison and Calculation Functions START --------------------- *
 */

/* Obtain Height of Node in AVL Tree */
int AVLHeight(TNode* N){
    if (N == NULL) return 0;
    return N->height;
}

/* Obtain the Max value between two integers */
int max(int a,int b){ return (a > b)? a : b; }

/* Obtain the Balance of the Node in an AVL Tree */
int AVLBalance(TNode* N){
    if (N == NULL) return 0;
    return AVLHeight(N->left) - AVLHeight(N->right);
}
/*
 * --------------------- CORE AVL Tree Internal Comparison and Calculation Functions END ----------------------- *
 */



