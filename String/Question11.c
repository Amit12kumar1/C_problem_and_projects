#include <stdio.h>
#include <string.h>

int main() {
    char str1[50];
    char str2[50], result[100];
    int i = 0, j = 0;

    printf("Enter first string: \n");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Enter second string: \n");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';

    printf("Concatenated string: %s\n", result);

    return 0;
}
