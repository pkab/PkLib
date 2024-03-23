//
// Created by rax on 3/20/24.
//

#ifndef PKLIB_RAWFILE_H
#define PKLIB_RAWFILE_H
#include <System/Files/Files.h>

File* FileOpen(const char* path);
int FileReadByte(File* f);
void FileClose(File* f);
#endif //PKLIB_RAWFILE_H
