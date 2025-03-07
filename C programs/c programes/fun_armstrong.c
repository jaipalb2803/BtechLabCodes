#include<stdio.h>
#include<math.h>
int main()
{  int a,b;
    a=readnum();
    ToPrint(a,ArmstrgNum(a));
}
int readnum(void)
{
   int n;
    printf("enter the number:");
    scanf("%d",&n);
   return(n);
}
int ArmstrgNum( int n)
{
   int count,r,sum;
   count=log10(n)+1;
   sum=0;
   while(n>0)
   {
      r=n%10;
      n=n/10;
      sum=sum+pow(r,count);
   }
   return(sum);
}
void ToPrint(int a,int b)
{
   (a==b)?printf("%d is armstrong number",a):printf("%d is armstrong number",a);
}
