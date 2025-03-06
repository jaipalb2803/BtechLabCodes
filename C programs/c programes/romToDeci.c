#include<stdio.h>
#include<string.h>
int deci(char c)
{
    int v=0;
    switch (c)
    {   
     case'I':v=1;
        break;
     case'V':v=5;
        break;
     case'X':v=10;
        break;
     case'L':v=50;
        break;
     case'C':v=100;
        break;
     case'D':v=500;
        break;
     case 'M':v=1000;
        break;
     case '\0':v=0;
        break;
     default:printf("This code valid upto M(1000)");
    }
    return(v);    
}
int main()
{
    int i,n=0;
    char s[100];
    printf("enter roman number=");
    scanf("%s",s);i=0;
    while(s[i])
    {
        if(deci(s[i])>=deci(s[i+1]))
            n+=deci(s[i]);
        else
        {
            n+=deci(s[i+1])-deci(s[i]);
            i++;
        }
        i++;
        
    } 
    printf("decimal equivalent=%d",n);   
}