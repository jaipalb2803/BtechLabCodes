#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[20],ch;
    int i=0;
    printf("Enter password : ");
    while((ch=getch())!=13)
    {
        if(ch=='\b')
        {
            printf("\b \b");
            i--;
        }
        else if(ch!='+'&&ch!='#')
        {
            printf("*");
            a[i]=ch;
            i++;
        }
       
    }
    a[i]='\0';
    printf("\nyour password : ");
    printf("%s",a);

}