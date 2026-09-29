    #include<stdio.h>
    int main(){
          char str[50];
            int lenght=0;
            int i=0;
                scanf("%s",str);
            while (str[i]!='\0')
            {
               lenght++;
               i++;
            }
            printf(" %d\n", lenght);
        


        return 0;
    }
