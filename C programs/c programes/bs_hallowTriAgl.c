#include<stdio.h>
int main()
{
   int n,i,j,s;
   printf("enter the number:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n-i;j++)
      {
         printf(" ");
      }
      for(j=0;j<1;j++)
      {
         printf("*");
      }
      for(j=1;j<i;j++)
      {
         (i!=n)?printf(" "):printf(" *");
      }
      for(j=2;j<i;j++)
      {
         printf(" ");
      }
      for(j=0;j<1&&i!=1;j++)
      {
         (i!=n)?printf("*"):printf(" ");
      }
      printf("\n");
   }
}