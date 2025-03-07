#include<stdio.h>
#include<string.h>
void ReadArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("enter a[%d]=",i+1);
        scanf("%d",&a[i]);
    }
}
int binarySearch(int a[],int n,int k)
{
    int s=0,l=n-1,m;
    m=(s+l)/2;
    while(s<=l)
    {
        if(a[m]==k)           
           break;
        else if(k>a[m])
            s=s+1;
        else if(k<a[m])
            l=l-1;
        m=(s+l)/2;
    }
    if(a[m]==k)
        return m;
    else
        return -1;
}
int main()
{
    int n,k,m;
    printf("enter no of elemets:");
    scanf("%d",&n);
    int a[n];
    ReadArray(a,n);
    printf("enter any key:");
    scanf("%d",&k);
    m=binarySearch(a,n,k);
    if(m>=0)
        printf("key found at position:%d ",m+1);
    else
        printf("key not found !");
}
