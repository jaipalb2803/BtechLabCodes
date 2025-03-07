#include<stdio.h>
#include<string.h>
int main()
{
   char a[100];
   printf("enter you string:");
   fgets(a,100,stdin);
   int j,i,c,k,n;
   n=strlen(a);
   c=0;
   for(i=n-2;i>=0;i--)
   {
       c++;
       if(a[i]==' '||i==0)
       {
            if(i==0)
             printf(" ");
            k=i;
           for(j=1;j<=c;j++)
           {
              printf("%c",a[k]);
              k++;
           }
           c=0;
       }
   }
}