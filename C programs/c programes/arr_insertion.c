#include<stdio.h>
int readArray(int a[],int n)
{
  int i=0;
  while (i<n)
  {
    scanf("%d",&a[i]);
    i++;
  }
  
}
void insertValue(int a[],int k,int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      if(k-1==a[i]&&k+1==a[i+1])
        printf("%2d%2d",a[i],k);
      else
        printf("%2d",a[i]);
   }
}
int main()
{
  int n,k;
  printf("enter num:");
  scanf("%d",&n);
  int a[n];
  readArray(a,n);
  printf("enter your insert value:");
  scanf("%d",&k);
  insertValue(a,k,n);

}


