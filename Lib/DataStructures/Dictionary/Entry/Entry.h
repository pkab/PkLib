#ifndef PKLIB_ENTRY_H
#define PKLIB_ENTRY_H
#include <DataStructures/Basic/Comparator/Comparator.h>

typedef struct ntry{
    void* key;
    u8 key_type;
    u64 keysize;
    void* value;
    u8 val_type;
    u64 valuesize;
}Entry;


void EntryInit(Entry* e, void* key, int key_size, u8 keytype, void* value, int value_size, u8 valtype);
void EntryPrint(Entry* e);
void EntryFree(Entry* e);

#endif //PKLIB_ENTRY_H
