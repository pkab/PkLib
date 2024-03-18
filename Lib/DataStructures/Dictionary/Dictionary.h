#ifndef PKLIB_DICTIONARY_H
#define PKLIB_DICTIONARY_H
#include <DataStructures/Lists/LinkedList/LinkedList.h>
#include <DataStructures/Dictionary/Entry.h>

typedef struct dict{
    LinkedList list;
    u8 type;
    u8 keytype;
}Dictionary;

void DictInit(Dictionary * dict);
void DictInsert(Dictionary * dict, Entry* e);
void PrintData(Dictionary *dict,Entry* b);
void DictFree(Dictionary * dict);
#endif //PKLIB_DICTIONARY_H
