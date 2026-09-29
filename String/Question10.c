#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[50];
  int  i, digit=0,special=0,alphabets=0;

    printf("Enter string: \n");
    fgets(str1, sizeof(str1), stdin);
 for (int i = 0; str1[i] != '\0'; i++) {
       if (str1[i]>='a' && str1[i]<='z'||str1[i]>='A' && str1[i]<='Z' )
       {
       alphabets++;
       }
       
       else if( str1[i]>='0'&& str1[i<='9']){
        digit++;
       }
       else{
        special++;
       }
    }
   printf(" nuber of alphabets is %d\n ",alphabets);
      printf("nuber of digit is %d\n ", digit);
   printf("nuber of special charecter  is %d\n ", special);




    return 0;
}
