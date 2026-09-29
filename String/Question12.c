#include <stdio.h>
#include <string.h>

int main() {
    char str1[50];
    int length = 0, isPalindrome = 1;

    printf("Enter a string: \n");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 
    while (str1[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) {
        if (str1[i] != str1[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome string.\n", str1);
    } else {
        printf("\"%s\" is not a palindrome string.\n", str1);
    }

    return 0;
}
