#include<stdio.h>
int main()
{
    // star pyramid 
    int i,j,n,s;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(s=1;s<=2*i-1;s++)
        {
            printf("*");
        }
        printf("\n");
    }
}