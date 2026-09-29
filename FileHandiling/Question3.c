#include <stdio.h>

int main() {
    char filename[100], text[1000];
    FILE *file;

    // Input the file name
    printf("Enter the file name to append: ");
    scanf("%s", filename);

    // Prompt for the text to append
    printf("Enter the text to append: ");
    getchar(); // Clear input buffer
    fgets(text, sizeof(text), stdin);

    // Open the file in append mode
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return 1;
    }

    // Append the text to the file
    fputs(text, file);

    // Close the file
    fclose(file);

    printf("Data appended successfully.\n");
    return 0;
}


/*
 Task: Add new data to an existing file without overwriting the previous content.
 Explanation :
 ● Openthefilein append (a) mode. This mode ensures new data is added to
 the end of the file without erasing existing content.
 ● Prompttheuser to provide the data they wish to append.
 ● Usefprintf() or fputs() to append the data.
 ● After appending, close the file. If the file does not exist, it is created.
 Input:
 Enter the file name to append: example.txt
 Enter the text to append: This is appended text.
 Output:
 Data appended successfully
 */