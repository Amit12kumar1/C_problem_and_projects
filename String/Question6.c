 #include<stdio.h>
 #include<string.h>
 int main(){
    char str[50];
          int i=0, count=0;
          fgets(str,sizeof(str),stdin);
          while (str[i]!=0)
          {
            if( (str[i]!=' '&& str[i]!='\n') && (i==0 || str[i-1]==' '|| str[i-1]=='\n')  )
            {
             count++;
            }
            i++;
          }
          
     printf("the total number of word is %d",count);
        
    return 0;
 }