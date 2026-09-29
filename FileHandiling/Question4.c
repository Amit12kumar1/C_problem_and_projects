#include <stdio.h>

int main() {
    char filename[100];
    FILE *file;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    // Input the file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++; // Count every character

        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Count words
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++; // New word found
        }
    }

    // If the file has at least one line
    if (characters > 0 && ch != '\n') {
        lines++;
    }

    // Close the file
    fclose(file);

    // Display the counts
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}

/*
Task: Count and display the number of characters, words, and lines in a file.
 Explanation:
 ● Openthefilein read mode.
 ● Readthefilecharacter by character using fgetc().
 ● Count:
 ○ Characters: Increment the count for every character read (excluding
 EOF).
 ○ Words: Increment the count when a space or newline is encountered.
 ○ Lines: Increment the count when a newline (\\n) is encountered.
 ● Display the counts.
 Input:
 Enter the file name: example.txt
 Output:
 Characters: 50
 Words: 8
 Lines: 2
 */