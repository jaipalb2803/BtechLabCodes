#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int a[],int n)
{
    for (int i = 0; i <n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void readArr(int a[],int n)
{
     for(int i=0;i<n;i++)
    {
        printf("Enter-%d=",i+1);
        scanf("%d",&a[i]);
    }
}
int partition(int a[], int l, int r)
{
    int i,j,pivot;
    i=l+1;
    j=r;
    pivot=/*(l==0)?a[r/2]:*/a[l];

    while(j>=i)
    {
        
        if(pivot<=a[i] && pivot>=a[j])
        {
            swap(&a[j],&a[i]);
            i++;
            j--;
        }
        if(pivot>=a[i])
            i++;
        if(pivot<a[j])
            j--;
       
    }
    //if(pivot>=a[j])
     swap(&a[j],&a[l]);
    
    return j;
}

void quicksort(int a[], int l, int r)
{
    if (r-l<1)
    {  
        return;
    } 
     
    int mid= partition(a, l, r);
    
    quicksort(a, l, mid-1); 
    
    quicksort(a, mid+1, r);
    
     
     

}

int main()
{
    int n;
    printf("Enter the no of elements=");
    scanf("%d",&n);
    int a[n];

    readArr(a,n);

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    printArr(a,n);

    return 0;
}
