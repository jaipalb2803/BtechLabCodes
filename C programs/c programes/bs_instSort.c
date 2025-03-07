#include<stdio.h>
#include<stdlib.h>

void readArray(int*a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       printf("enter arr-%d=",i+1);
       scanf("%d",&a[i]);
    }
}
void insertionSort(int *a,int n)
{
    int i,j,e;
    for(i=1;i<n;i++)
    {
        e=a[i];
        j=i-1;
        while(j>=0 && e<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=e;
    }
}
void printArray(int*a,int n)
{
    int i;
    printf("sorted order by insertion: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
} 
int main()
{
    int n;
    system("cls");
    printf("enter the number:");
    scanf("%d",&n);
    int a[n],i;
    readArray(a,n);
    insertionSort(a,n);
    printArray(a,n);
}