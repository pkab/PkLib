#include <DataStructures/Dictionary/Dictionary.h>
#include <stdio.h>

int main() {
    Dictionary dict;
    Entry e;
    int a=10;
    char b[20] ="Hello World";
    EntryInit(&e,&a,4,Int,b,20,String);
    EntryPrint(&e);
    DictInit(&dict);
    DictInsert(&dict,&e);
    PrintData(&dict,&e);
    return 0;
}
