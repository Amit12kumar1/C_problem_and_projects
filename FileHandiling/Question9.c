#include <stdio.h>

int main() {
    char file1[100], file2[100], outputFile[100];
    FILE *source1, *source2, *destination;
    char ch;
    // Input file names
    printf("Enter the first file: ");
    scanf("%s", file1);
    printf("Enter the second file: ");
    scanf("%s", file2);
    printf("Enter the output file: ");
    scanf("%s", outputFile);
    // Open the first file in read mode
    source1 = fopen(file1, "r");
    if (source1 == NULL) {
        printf("Error: Could not open file %s.\n", file1);
        return 1;
    }
    // Open the second file in read mode
    source2 = fopen(file2, "r");
    if (source2 == NULL) {
        printf("Error: Could not open file %s.\n", file2);
        fclose(source1);
        return 1;
    }
    // Open the output file in write mode
    destination = fopen(outputFile, "w");
    if (destination == NULL) {
        printf("Error: Could not open file %s.\n", outputFile);
        fclose(source1);
        fclose(source2);
        return 1;
    }
    // Write the content of the first file to the output file
    while ((ch = fgetc(source1)) != EOF) {
        fputc(ch, destination);
    }
    // Write the content of the second file to the output file
    while ((ch = fgetc(source2)) != EOF) {
        fputc(ch, destination);
    }
    // Close all files
    fclose(source1);
    fclose(source2);
    fclose(destination);
    printf("Files merged successfully into %s.\n", outputFile);
    return 0;
}




/*
 9. Merge Two Files
 Task: Merge the contents of two files into a third file.
 Explanation:
 ● Openbothsource files in read mode and the destination file in write mode.
 ● Readcontent from the first file and write it to the destination file.
 ● Repeatthe sameprocess for the second file.
 ● Ensurethe contents are appended sequentially.
 ● Closeall files after merging.
 Input:
 Enter the first file: file1.txt
 Enter the second file: file2.txt
 Enter the output file: merged.txt
 Output:
 Files merged successfully into merged.txt.
 */