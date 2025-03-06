#include<stdio.h>
int main()
{
   //c programe for generic root
   int n,sum,r,k;
   printf("enter the number\n");
   scanf("%d",&n);k=n;
   while(n>9)
   {
     sum=0;
     while(n>0)
     {
        r=n%10;
        sum=sum+r;
        n=n/10;
     }
     n=sum;
   }
   printf("Final single digit number is=%d generic root of %d",n,k);
}