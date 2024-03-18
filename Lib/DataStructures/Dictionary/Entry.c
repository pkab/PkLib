#include "Entry.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void EntryInit(Entry* e, void* key, int key_size, u8 keytype, void* value, int value_size, u8 valtype){
    e->key= malloc(key_size);
    e->keysize = key_size;
    e->key_type = keytype;
    e->value = malloc(value_size);
    e->valuesize = value_size;
    e->val_type = valtype;
    memcpy(e->key,key,key_size);
    memcpy(e->value,value,value_size);

}
void EntryPrint(Entry* e){
    switch(e->key_type){
        case I8:
        case I16:
        case I32:
        case Int:
            printf("{ %d :",*(int*)e->key); break;
        case I64:
            printf("{ %ld :",*(i64*)e->key); break;
        case U8:
        case U16:
        case U32:
            printf("{ %u :",*(u32*)e->key); break;
        case U64:
            printf("{ %lu :",*(u64*)e->key); break;
        case String:
            printf("{ %s :",(char*)e->key); break;
    }
    switch(e->val_type){
        case I8:
        case I16:
        case I32:
        case Int:
            printf(" %d }",*(int*)e->value); break;
        case I64:
            printf(" %ld }",*(i64*)e->value); break;
        case U8:
        case U16:
        case U32:
            printf(" %u }",*(u32*)e->value); break;
        case U64:
            printf(" %lu }",*(u64*)e->value); break;
        case String:
            printf(" %s }",(char*)e->value); break;
    }
    printf("\n");
}
void EntryFree(Entry* e){
    free(e->key);
    free(e->value);
}