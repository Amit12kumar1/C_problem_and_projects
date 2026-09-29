 #include<stdio.h>
 #include<string.h>
  #include<ctype.h>

 int main(){
    char str[50];
          int constant=0, vovel=0;
          printf("enter  a string \n ");
          fgets(str,sizeof(str),stdin);
for (int i = 0; i < str[i]!='\0'; i++)
{
    char input=tolower(str[i]);
    if(str[i]>='a'&&str[i]<='z'){
        if(input=='a'||input=='e'||input=='i'||input=='o'||input=='u'){
            vovel++;
        }
        else{
            constant++;
        }
    }
}


          
          
     printf("\n the total number of constant is %d",constant);
            printf("\n the total number of vovel is %d",vovel);
 
    return 0;
 }