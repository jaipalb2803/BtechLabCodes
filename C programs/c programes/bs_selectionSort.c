#include<stdio.h>
#include<string.h>
void readArray(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("enter a[%d]=",i+1);
    scanf("%d",&a[i]);
  }

}
int minArray(int a[],int k,int n)
{
  int min=a[k],i,pos;
  for(i=k;i<n;i++)
  {
        if(min>a[i])
        {
            pos=i;
        }
  }
  return pos;
}
void selectionSort(int a[],int n)
{
   int m,temp;
   for(int i=0;i<n-1;i++)
   {
        m=minArray(a,i,n);
        temp=a[i];
        a[i]=a[m];
        a[m]=temp;
   }
}
void printArray(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }

}
int main()
{
   int n;
   printf("Enter no of elements:");
   scanf("%d",&n);
   int a[n];
   readArray(a,n);
   selectionSort(a,n);
   printArray( a,n);
}