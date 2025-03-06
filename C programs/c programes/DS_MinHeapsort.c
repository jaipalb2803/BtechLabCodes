#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i) 
{
    int par = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[par])
        par = l;

    if (r < n && a[r] < a[par])
        par= r;

    if (par != i)
     {
        swap(&a[i], &a[par]);
        heapify(a,n, par);
    }
}
void heapsort(int arr[], int n) 
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   for (i = n - 1; i >= 0; i--)
	 {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
	int n;
	printf("Enter no of element:");
	scanf("%d",&n);
	int a[n];

	for(int i=0;i<n;i++)
	{
		printf("enter-%d:",i+1);
		scanf("%d",&a[i]);
	}
	
	heapsort(a,n);

	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}

}