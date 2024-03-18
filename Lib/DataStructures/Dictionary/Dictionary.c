#include "Dictionary.h"
void DictInit(Dictionary * dict){
    ListInit(&dict->list);
    dict->type=entry;
}
void DictInsert(Dictionary * dict, Entry* e){
//    Entry e;
//    EntryInit(&e,key,key_size,key_type,val,val_size,val_type);
    ListInsert(&dict->list,e,dict->type,sizeof(Entry));
}
void PrintData(Dictionary *dict, Entry* b){
    Entry* e = (Entry*)dict->list.head->data;
    if(e){
        EntryPrint(e);
    }
}

void DictFree(Dictionary * dict){
    ListFree(&dict->list);
}
