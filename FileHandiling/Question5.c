#include <stdio.h>
int main() {
    char sourceFile[100], destFile[100];
    FILE *source, *destination;
    char ch;
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
    // Open the destination file in write mode
    destination = fopen(destFile, "w");
    if (destination == NULL) {
        printf("Error: Could not open destination file %s.\n", destFile);
        fclose(source);
        return 1;
    }
    // Copy data from source file to destination file
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    // Close the files
    fclose(source);
    fclose(destination);
    printf("Data copied successfully from %s to %s.\n", sourceFile, destFile);
    return 0;
}


/*
 Copy Data from One File to Another
 Task: Copy the contents of one file into another.
 Explanation:
 ● Openthesource file in read (r) mode and the destination file in write (w)
 mode.
 ● Readdatafromthe source file using fgetc() or fgets() and write it to the
 destination file using fputc() or fputs().
 ● Ensurethe file handles are closed after copying.
 ● Handleerrors if the source file does not exist.
 Input:
 Enter the source file: example.txt
 Enter the destination file: copy.txt
 Output:
 Data copied successfully from example.txt to copy.txt
 */