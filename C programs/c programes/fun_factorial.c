#include<stdio.h>
int main()
{   
   PrintN(fact(ScanN()));
}
int ScanN(void)
{ 
    int n;
    printf("entre the number:");
    scanf("%d",&n);
    return(n);
}
int fact(int x)
{
   int i,p;
   p=1;
   for(i=1;i<=x;i++)
   {
      p=p*i;
   }
   return(p);
}
void PrintN(int p)
{
    printf("factorial of your number is %2d",p);
}