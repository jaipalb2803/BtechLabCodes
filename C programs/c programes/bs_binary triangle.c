#include<stdio.h>
int main()
{
    //c programe for binary triangle
    int i,j,n;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=i;j++)
      {
        if(i%2==0)
         (j%2==0)?printf("1"):printf("0");
       else
         (j%2==0)?printf("0"):printf("1");
      }
     printf("\n");
    }
}