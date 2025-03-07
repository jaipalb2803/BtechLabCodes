#include<stdio.h>

int push(int a[],int t,int ele,int n)
{
	if(t==n-1)
	{
		printf("STACK IS FULL\n");
	}
	else
	{
		t++;
		a[t]=ele;
	}
	return t;
}
void printArr(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
}
int pop(int a[],int*t)
{
	if((*t)==-1)
		printf("\nSTACK IS EMPTY");
	else
	{
		(*t)--;
		return(a[*t+1]);
	}
}
int main()
{
	int top,n,ele;
	printf("Enter the no of ele?:");
	scanf("%d",&n);
	int a[n];
	top=-1;
	for(int i=0;i<=n;i++)
	{
		if(i<n)
		{
			printf("enter a[%d]=",i);
		 	scanf("%d",&ele);
		}
		top=push(a,top,ele,n);
	}
	printArr(a,n);
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		ele=pop(a,&top);
		if(i<n)
			printf("%3d",ele);
	}


}