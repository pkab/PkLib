#include <System/Files/RawFiles/RawFile.h>
#include <stdio.h>

int main() {
    FILE *file_ptr;
    char buffer[200];

    file_ptr = fopen("../SampleText.txt", "rb"); // Open text file in binary mode
    if (file_ptr == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read from the file
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file_ptr);
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Output the read data
    printf("Read from file: %s", buffer);

    // Close the file
    fclose(file_ptr);

    return 0;
}
