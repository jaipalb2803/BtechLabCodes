#include<stdio.h>
#include<string.h>
#define m 200

int main()
{
   int w=0,l=1,ch=0;
   char s[m];
   system("cls");
   printf("enter the any para end with*(star):\n");
   int i=0;
   do
   {
     s[i]=getchar();
     i++;
   }while(s[i-1]!='*');
   i=0;
   while(s[i]!='*')
   {
       
       if(s[i]==' '||s[i]==','||s[i]=='.')
       {
            w++;
       }
       else if(s[i]=='\n')
       {
            l++; 
            w++;
       }
       else
       { 
            ch++;
       }
     i++;
   }
   printf("no of line:%d",l);
   printf("\nno of words:%d",w+1);
   printf("\nno of charecters:%d",ch);
}
