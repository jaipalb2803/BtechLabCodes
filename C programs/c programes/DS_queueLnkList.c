#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct  node *link;
}node;

void enqueue(node**first,node**last,int n)
{
	node*new;
	for(int i=1;i<=n;i++)
	{
		printf("enter ele[%d]=",i);
		new=(node*)malloc(sizeof(node));
		scanf("%d",&new->data);
		new->link=NULL;
		if(*first==NULL)
		{
			*first=*last=new;
		}
		else
		{
			(*last)->link=new;
			*last=new;
		}
	}
}
void printQueue(node*first,node*last)
{
	if(first==NULL)
		printf("QUEUE IS EMPTY");
	else
	{   node*temp=first;
		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->link;
		}
		if(temp==NULL)
			printf("\tQUEUE IS FULL");
	}
}
void dequeue(node**first)
{
	node*temp;
	while(*first)
	{
		temp=*first;
		*first=(*first)->link;
		free(temp);
	}
}
int main()
{
	node*first,*last;
	first=NULL;
	last=NULL;
	int n;
	printf("Enter no of nodes?:");
	scanf("%d",&n);

	enqueue(&first,&last,n);
	printf("After insertion:\n");
	printQueue(first,last);

	printf("\nAfter deletion:");
	dequeue(&first);
    printQueue(first,last);
}
