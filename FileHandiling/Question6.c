#include <stdio.h>
int main() {
    char filename[100];
    // Input the file name
    printf("Enter the file name to delete: ");
    scanf("%s", filename);

    // Attempt to delete the file
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        printf("Error: Could not delete file %s. It may not exist.\n", filename);
    }

    return 0;
}

/*
 6. Delete a File
Task: Delete a specified file from the system.
 Explanation:
 ● Usetheremove() function to delete the file.
 ● Prompttheuser for the file name.
 ● Ifthe file is deleted successfully, print a success message. If the file doesn’t
 exist, display an error message.
 Input:
 Enter the file name to delete: example.txt
 Output:
 File example.txt deleted successfully.
 */