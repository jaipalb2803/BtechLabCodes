#include<stdio.h>
#include<stdlib.h>

void enqueue(int Q[],int*R,int*F,int ele,int N )
{
      if (*R==N-1)
	  	printf("QUEUE IS FULL\n");
	  else
	  {
		 *R=*R+1;
		 Q[*R]=ele;
	  }
	  if(*F==-1)
	  	*F=*F+1; 

}
void dequeue(int a[],int*R,int*F)
{
	if(*F==*R+1)
	{
		*F=*R=-1;
		printf("\nQUEUE IF EMPTY");
	}
	else
	{
		printf("%3d",a[*F]);
		*F=*F+1; 
	}
	   
}
int main()
{
	int n,F,R;
	printf("Enter the no of ele?:");
	scanf("%d",&n);
	int a[n];
	F=R=-1;
	for(int i=0;i<=n;i++)
	{
		int ele;
		if(i<n)
		{
			printf("enter ele[%d]=",i+1);
			scanf("%d",&ele);
		}
		enqueue(a,&R,&F,ele,n);
	}
	for(int i=0;i<=n;i++)
	{
		dequeue(a,&R,&F);
	}
}
