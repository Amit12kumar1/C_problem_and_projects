#include <stdio.h>
#include <string.h>
int main() {
    char sourceFile[100], destFile[100];
    FILE *source, *destination;
    char buffer[1000];
    int length;
    // Input the source and destination file names
    printf("Enter the source file: ");
    scanf("%s", sourceFile);
    printf("Enter the destination file: ");
    scanf("%s", destFile);
    // Open the source file in read mode
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Could not open source file %s.\n", sourceFile);
        return 1;
    }
    // Read the content of the source file into a buffer
    fseek(source, 0, SEEK_END); // Move to the end of the file
    length = ftell(source);    // Get the file size
    fseek(source, 0, SEEK_SET); // Move back to the start of the file
    fread(buffer, sizeof(char), length, source);
    buffer[length] = '\0'; // Null-terminate the string
    // Reverse the content in the buffer
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }
    // Open the destination file in write mode
    destination = fopen(destFile, "w");
    if (destination == NULL) {
        printf("Error: Could not open destination file %s.\n", destFile);
        fclose(source);
        return 1;
    }
    // Write the reversed content to the destination file
    fputs(buffer, destination);
    // Close both files
    fclose(source);
    fclose(destination);
    printf("Content reversed and written to %s.\n", destFile);
    return 0;
}
/*
8. Reverse File Content
 Task: Reverse the content of a file and write it to a new file.
 Explanation:
 ● Openthesource file in read mode and read its content into a buffer (e.g., an
 array).
 ● Usestring manipulation techniques to reverse the buffer content.
 ● Openadestination file in write mode and write the reversed content to it.
 ● Closeboth files.
 Input:
 Enter the source file: input.txt
 Enter the destination file: reversed.txt
 Output:
 Content reversed and written to reversed.txt
 */