#include <DataStructures/Trees/AVLTree.h>
#include <stdio.h>
int main() {
    AVLTree tree;
    AVLInit(&tree,U8,1);
    u8 arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++) AVLInsert(&tree,&arr[i]);
    printf("In Order Traversal-----\n");
    AVLPrint(&tree,0);
    printf("Pre Order Traversal-----\n");
    AVLPrint(&tree,1);
    printf("Post Order Traversal-----\n");
    AVLPrint(&tree,2);
    AVLSearch(&tree, &arr[3]);
    AVLDelete(&tree,&arr[9]);
    AVLPrint(&tree,0);
    AVLFree(&tree);
    return 0;
}
