#include<stdio.h>
int main()
{
    // pyramid with number_pascal triangle
    int i,j,n,s,c;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        { 
            printf(" ");
        }
        for(s=1,c=1;s<=i;s++,c++)
        { 
            printf("%d",c);
        }
        c--;
        for(s=1;s<i;s++)
        {
             c--;
             printf("%d",c);
        }
       printf("\n");
    }
}