#include <DataStructures/Lists/Stack/Stack.h>
#include <stdio.h>
int main() {
    int a = 42, b = 36;
    double s = 52.25f;
    char c = 'A';
    char w[16] = "Hello World\0";
    Stack list;
    StackInit(&list);
    StackPush(&list,w,String,16);
    StackPush(&list,&a,Int,1);
    StackPush(&list,&b,Int,1);
    StackPush(&list,&s,Double,1);
    StackPush(&list,&c,Char,1);
    StackPrint(&list);
    StackPop(&list);
    printf("----------------------\n");
    StackPrint(&list);
    StackPop(&list);
    printf("----------------------\n");
    StackPrint(&list);
    StackPop(&list);
    StackPop(&list);
    StackPop(&list);
    StackPop(&list);
    StackFree(&list);
    return 0;
}
