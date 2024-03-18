#include "Comparator.h"
#include "DataStructures/Dictionary/Entry/Entry.h"
#include <string.h>
int compare(void* data1, void *data2, u8 type){
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
            if (*(int*)data1 < *((int*)data2)) return 1;
            else if(*(int*)data1 == *(int*)data2) return 0;
            else return -1;
        case I32:
            if (*(i32*)data1 < *((i32*)data2)) return 1;
            else if(*(i32*)data1 == *(i32*)data2) return 0;
            else return -1;
        case I64:
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
        case entry:
            return compare(((Entry*)data1)->key,((Entry*)data2)->key,((Entry*)data1)->key_type);
        case Other:
            if(data1<data2) return 1;
            else return -1;
    }
}