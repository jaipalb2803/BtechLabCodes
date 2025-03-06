#include<stdio.h>
int main()
{
    // star pyramid with aphabats-rows
    int i,j,n,s;char c;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { 
        c='A';
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(s=1;s<=2*i-1;s++,c++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
}