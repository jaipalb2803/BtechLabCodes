#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
}node;

void push(node**first,int ele)
{
	node*new=(node*)malloc(sizeof(node));
	new->data=ele;
	if(first==NULL)
	{
		new->link=NULL;
		*first=new;
	}
	else
	{
		new->link=*first;
		*first=new;
	}
}
void createNode(node**first,int n)
{
	int ele;
	for(int i=0;i<=n;i++)
	{
		if(i<n)
		{
			printf("enter the data-%d:",i+1);
			scanf("%d",&ele);
			push(first,ele);
		}
		else
			printf("STACK IS FULL\n");
	}
}
void pop(node**first,int n)
{
	node*temp;
	for(int i=n;i>=0;i--)
	{
		if(i==0)
			printf("\nSTACK IS EMPTY");
		else
		{
			temp=*first;
		    printf("%d\t",(*first)->data);
			*first=(*first)->link;
			free(temp);
		}
		
	}

}
int main()
{
	int n;
	printf("Enter the no of nodes?:");
	scanf("%d",&n);
	node *first=NULL;

	createNode(&first,n);	
	pop(&first,n);


}