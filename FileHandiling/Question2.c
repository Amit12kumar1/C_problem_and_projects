#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100], line[1000];
    FILE *file;

    // Input the file name
    printf("Enter the file name to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }

    printf("Contents of the file:\n");

    // Read and display the file content line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    return 0;
}



/*
2. Read Data from a File
 Task: Read and display the content of a file.
 Explanation :
 ● Theprogramopens the file in read (r) mode. If the file does not exist, the
 program should handle the error gracefully.
 Thecontent of the file is read using the fgets() function or fscanf() function,
 line by line or word by word.
 ● Theprogramdisplays the content to the console.
 ● After reading, the file is closed to release resources.
 Input:
 Enter the file name to read: example.txt
 Output:
 Contents of the file:
 Hello, File Handling in C!
*/