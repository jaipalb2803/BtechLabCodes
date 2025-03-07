#include<stdio.h>
int main()
{
   //c programe for sum of n factorials
   int i,j,n,p,sum;
   printf("entre the number:");
   scanf("%d",&n);sum=0;
   for(i=1;i<=n;i++)
   {
      p=1;
      for(j=1;j<=i;j++)
      {
         p=p*j;
      }
      sum=sum+p;
      printf("%3d!",i);
   }
  printf("\nsum of series=%2d",sum); 
}