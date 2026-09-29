//  #include<stdio.h>
//  #include<string.h>
//   #include<ctype.h>

//  int main(){
//     char str[50];
//           int count[200]={0};
//           printf("enter  a string \n ");
//           fgets(str,sizeof(str),stdin);
// for (int i = 0; i < str[i]!='\0'; i++)
// {
//   count[(unsigned char)str[i]]++;


// }
// printf("Repeted character\n");
// for (int i = 0; i <23; i++)
// {
  

// if (count[i]>1)
// {
//  printf(" %s\n", str[i]);
// }

// }


          
          
 
//     return 0;
//  }

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[50];
    int count[256] = {0}; 

    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin);

    
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    printf("Repeated characters:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 1) { 
            printf("'%c' appears %d times\n", i, count[i]);
        }
    }

    return 0;
}
