    #include<stdio.h>
    #include<string.h>
    int main(){
          char org[50];
             char cpy[50];    
        scanf("%[^]s", org);
            strcpy(cpy,org);
            printf(" original string %s",org);
 printf("\n copy string %s",cpy);


        return 0;
    }
