#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*link;
	
};
typedef struct node Node;

Node* createCLL(Node*first,Node**last)
{
	int n;
	Node*temp,*new;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("ENTER LIST:");
	for(int i=1;i<=n;i++)
	{
		new=(Node*)malloc(sizeof(Node));
		printf("\nEnter Data-%d:",i);
		scanf("%d",&new->data);
		new->link=NULL;
		if(first==NULL)
		{
			temp=first=new;
		}
		else
		{
			temp->link=new;
			temp=new;
		}
	}
	*last=temp;
	temp->link=first;
	return(first);
}
Node* insert(Node*first,Node*last)
{
	int n;
	Node* temp=first;
    Node*new=(Node*)malloc(sizeof(Node));
    printf("Enter the insert elements:");
    scanf("%d",&new->data);
	new->link=NULL;

	printf("Enter the insert position:");
    scanf("%d",&n);

    for(int i=1;i<n-1;i++)
	{
		temp=temp->link;
	}
	if(n!=1)
	{
		new->link=temp->link;
		temp->link=new;
	}
	else
	{
		new->link=first;
		last->link=new;
		first=new;
	}
    return(first);

}
Node* delete(Node*first,Node*last)
{
	int n;
	Node* temp,*back;
	back=temp=first;
	printf("Enter the delete position:");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
	{
		temp=temp->link;
		if(i>2)
			back=back->link;
	}
	if(n!=1)
	{
		back->link=temp;
	}
	else
	{
		free(back);
		last->link=temp;
		first=temp;
	}
    return(first);

}
void printCLL(Node*first)
{
	Node*temp;
	temp=first;
	printf("CLL-LIST:");
	do
	{
		printf("%3d",temp->data);
		temp=temp->link;
	} while (temp!=first);
	
}
int main()
{
	Node *first=NULL,*last;
	first=createCLL(first ,&last);
	int n;
	do
	{
		printf("\nEnter your choice:\n1.insert\n2.delete\n3.exit\nChoice:");
		scanf("%d",&n);
		switch (n)
		{
		  case 1:first=insert(first,last);
			  printCLL(first);
			  break;
		  case 2:first=delete(first,last);
		  	   printCLL(first);
			   break;
		  case 3:printf("PROCCESS EXIT");
			   break;
		  default:printf("Enter the correct choice..!!");

		};

	} while (n!=3);
	
}