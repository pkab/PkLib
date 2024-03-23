#ifndef PKLIB_FILES_H
#define PKLIB_FILES_H
#include <stdio.h>

typedef struct files{
    FILE* file;
    char* filename;
    char* extension;
    void* data;
    unsigned char type_size;
    unsigned long size;
}File;
unsigned long FileSize(char* path);
char* FileType(char* path);

#endif
