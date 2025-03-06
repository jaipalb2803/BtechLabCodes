#include<stdio.h>
int main()
{
    //c programe for pascal triangle with aphabets
    int i,j,n,s;char c;
    printf("entre the number of rows=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n-i;j++)
      {
        printf(" ");
      }
      for(s=1,c='A';s<=i;s++,c++)
      {
        printf("%c",c);
      }
      c--;
      for(s=1;s<i;s++)
      {
        c--;
        printf("%c",c);
      }
     printf("\n");
    }
}