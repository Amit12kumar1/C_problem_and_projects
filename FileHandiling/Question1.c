

#include <stdio.h>

int main() {
    char filename[100], text[1000];
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", filename);

    printf("Enter the text to write: ");
    getchar(); // Clear input buffer
    fgets(text, sizeof(text), stdin);

    file = fopen(filename, "w"); // Open file in write mode
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fputs(text, file); // Write text to file
    fclose(file);      // Close file

    printf("File written successfully.\n");
    return 0;
}

/*
 Write a program to create a file and write a user-provided string into it.
 Explanation:
 ● Theprogramshould open a file in write (w) mode.
 ● Ifthe file doesn’t exist, it will be created automatically. If it exists, its content
 will be erased.
 ● Theuserprovides a string that is written to the file using the fprintf() or
 fputs() function.
 ● After writing, the file is closed using fclose().
 Input:
 Enter the file name: example.txt
 Enter the text to write: Hello, File Handling in C!
 Output:
 File written successfully.

 */