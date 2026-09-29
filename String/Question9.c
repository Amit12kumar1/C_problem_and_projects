#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[50];
    char str2[50];
   int i=0,isEqual=1;
    printf("Enter first string: \n");
    fgets(str1, sizeof(str1), stdin);
 printf("Enter second string: \n");
    fgets(str2, sizeof(str2), stdin);
    while (str1[i]!='\0' || str2[i]!='\0')
    {
      if(  str1[i]!=str2[i]){
      isEqual=0;
      break;
      }
i++;
    }
    if (isEqual==1)
    {
       printf("String are equal \n");
    }
    else{
        printf("String are not equal \n"); 
    }



    return 0;
}
