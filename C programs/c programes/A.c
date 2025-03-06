#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 50

char stk[S];
int t=-1;

char* infixToPost(char s[])
{
    char *p=(char*)malloc(strlen(s+1)*sizeof(char));
    int i=0,j=0;
    while(s[i]!='\0')
    {
         if(inOpr(s[i]))
         {
            p[j]==s[i];
            i++;
            j++;
         }
         else
         {
            if(prec(s[i]))
            {
              p[j]==s[i];
              i++;
              j++;
            }
           else
           {
              
           }
        }
    }

}
int main()
{
    char s[S];
    printf("enter the infix expression:");
    scanf("%s",s);
    char *p=infixToPost(s);
    printf("%s",p);
}
