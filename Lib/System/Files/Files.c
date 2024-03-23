#include "Files.h"
#include <string.h>
unsigned long FileSize(char* path){
    FILE *file = fopen(path, "r");
    if(file){
        fseek(file, 0, SEEK_END);
        unsigned long size = ftell(file);
        fseek(file, 0,SEEK_SET);
        fclose(file);
        return size;
    }
    return 0;

}
char* FileType(char* path){
    FILE *file = fopen(path, "r");
    char* filename = strdup(filename);
    char* dot = strrchr(filename,'.');
    printf("File Type: %s\n", dot ? strdup(dot+1): strdup(""));
    fclose(file);
    return dot;
}