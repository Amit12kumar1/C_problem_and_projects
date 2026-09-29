#include <stdio.h>
#include <string.h>
int main() {
    char filename[100], word[100], temp[100];
    FILE *file;
    int count = 0;
    // Input the file name
    printf("Enter the file name: ");
    scanf("%s", filename);
    // Input the word to count
    printf("Enter the word to count: ");
    scanf("%s", word);
    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }
    // Read words from the file and count matches
    while (fscanf(file, "%s", temp) != EOF) {
        if (strcmp(temp, word) == 0) {
            count++;
        }
    }
    // Close the file
    fclose(file);
    // Display the result
    printf("The word '%s' appears %d times in the file.\n", word, count);
    return 0;
}



/*
 7. Count Occurrences of a Word in a File
 Task: Find how many times a specific word appears in a file.
 Explanation:
 ● Openthefilein read mode.
 ● Readthefileline by line or word by word using fscanf() or fgets().
 ● Compareeachwordwith the given word using strcmp() to count matches.
 ● Display the total count.
 Input:
 Enter the file name: textfile.txt
 Enter the word to count: File
 Output:
 The word 'File' appears 3 times in the file
 */