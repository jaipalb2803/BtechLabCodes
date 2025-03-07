#include<stdio.h>
int main()
{
    // Empty space square
    int i,j,n,s;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==1||j==1||i==n||j==n)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
}