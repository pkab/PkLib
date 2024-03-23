#include "BinFiles.h"
#include <stdlib.h>
#include <string.h>

File* BinFileOpen(const char* path){
    char filepath[256];
    sprintf(filepath,"%s",path);
    File* f = (File*)malloc(sizeof(File));
    if(f==NULL){
        perror("Memory Allocation Failed");
        return NULL;
    }
    f->file = fopen(filepath, "rw+b");
    if (f->file == NULL) {
        perror("Failed to open file");
        free(f);
        return NULL;
    }
    f->filename = strdup(strrchr(filepath,'/')?strrchr(filepath,'/')+1:filepath);
    char* dot = strrchr(f->filename,'.');
    f->extension = dot ? strdup(dot+1):strdup("");

    fseek(f->file, 0, SEEK_END);
    f->size = ftell(f->file);
    fseek(f->file, 0,SEEK_SET);
    /* Allocate memory for file data and read the content into it */
    f->data = malloc(f->size);
    if (f->data == NULL) {
        perror("Memory allocation failed");
        fclose(f->file);
        free(f->filename);
        free(f->extension);
        free(f);
        return NULL;
    }
    fread(f->data, f->size, 1, f->file);
    return f;
}
int BinFileRead(File* f){

}
void BinFileClose(File* f){
    if (f != NULL) {
        if (f->file != NULL) {
            fclose(f->file);
        }
        free(f->filename);
        free(f->extension);
        free(f->data);
        free(f);
    }
}