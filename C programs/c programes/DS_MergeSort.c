#include <stdio.h>

void merge(int A[], int L[], int l, int R[], int r)
 {
    int i = 0, j = 0, k = 0;
    while (i < l && j < r)
     {
        if (L[i] <= R[j]) 
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < l)
    {
         A[k] = L[i];
        i++;
        k++;
    }
    while (j < r) 
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int n) 
{
    if (n < 2)
     {
        return;
    }

    int mid = n/ 2;
    int L[mid],R[n - mid];

    for (int i = 0; i < mid; i++) 
    {
        L[i] = A[i];
    }

    for (int i = mid; i < n; i++) 
    {
        R[i - mid] = A[i];
    }

    mergeSort(L, mid);
    mergeSort(R, n- mid);
    merge(A, L, mid, R, n- mid);
    
}
void readArr(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter-%d=",i+1);
        scanf("%d",&A[i]);
    }
}
void printArr(int B[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",B[i]);
    }   
}
int main()
{
    int n;
    printf("Enter no of elements=");
    scanf("%d",&n);
    int A[n];

    readArr(A,n);

    mergeSort(A,n);

    printArr(A,n);

}