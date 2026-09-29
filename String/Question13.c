#include <stdio.h>
#include <string.h>

int main() {
    char str1[50];
    int i;

    printf("Enter a string: \n");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 
  for (int i = 0; i < str1[i]!='\0'; i++)
  {
   if(str1[i]>='a' && str1[i]<='z'){
    str1[i]=str1[i]-32;
   }
   else if(str1[i]>='A' && str1[i]<='Z'){
    str1[i]=str1[i]+32;
   }
   
  }
  
   printf("Modify string %s\n",str1);


    return 0;
}
