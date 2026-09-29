#include<stdio.h>
    #include<string.h>
    int main(){
          char str[50];  
           int i=0;
        scanf("%[^\n]s", str);
       
        while (str[i] != '\0')
        {
           printf(" %c ", str[i]);
           i++;
        }
        
printf("\n");


        return 0;
    }