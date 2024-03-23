#ifndef PKLIB_BINFILES_H
#define PKLIB_BINFILES_H
#include <System/Files/Files.h>

File* BinFileOpen(const char* path);
int BinFileRead(File* f);
void BinFileClose(File* f);
#endif //PKLIB_BINFILES_H
