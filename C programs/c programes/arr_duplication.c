#include <stdio.h>
int main()
{
  int n,i,j,c;
  printf("entre the how many num u want:");
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
    printf("element-%d=",i+1);
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
       if(a[j]>a[j+1])
       {
            c=a[j];
            a[j]=a[j+1];
            a[j+1]=c;
       }
    }
  }
  for(i=0;i<n;i++)
  {
      if(a[i]<a[i+1]||a[i]>a[n-2])
       printf("%3d",a[i]);
  }
}