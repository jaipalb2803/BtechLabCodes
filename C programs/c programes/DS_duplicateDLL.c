
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *pred;
	struct node *succ;
};
typedef struct node dllNode;
void insertLeftmost(dllNode **left,dllNode **right,int ele)
{
	dllNode *new;
	new = (dllNode *)malloc(sizeof(dllNode));
	new->data = ele;
	if(*left == NULL)
	{
		*left = *right = new;	
		new->pred = new->succ = NULL;	
	}
	else
	{
		new->pred = NULL;
		new->succ = *left;
		(*left)->pred = new;
		*left = new;
	}
}
void createDLL(dllNode **left,dllNode **right)
{
	int n,i,ele;
	printf("How many nodes? ");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		printf("\nEnter element %d : ",i);
		scanf("%d",&ele);
		insertLeftmost(left,right,ele);
	}
}
void duplicate(dllNode**left,dllNode**right)
{
	dllNode*temp=NULL,*cur=NULL,*k;
	temp=cur=*left;
	temp=temp->succ;
	while(temp!=NULL)
	{
		while(cur->data==temp->data&&temp->succ!=NULL)
		{
			k=temp;
			temp=temp->succ;
			free(k);
		}
		if(cur->data==temp->data)
		{
			cur->succ=NULL;
			*right=cur;
			free(temp);
			break;
		}
		else
		{
			cur->succ=temp;
			temp->pred=cur;
			cur=temp;
			temp=temp->succ;
		}
	}
	
}
void printLR(dllNode *left)
{		
		dllNode *temp = NULL;
		printf("List L-->R : ");
		temp = left;
		while(temp != NULL)
		{
			printf("%3d",temp->data);
			temp = temp->succ;
		}	
		printf("\n");
}
void printRL(dllNode *right)
{		
		dllNode *temp = NULL;
		printf("List R-->L : ");
		temp = right;
		while(temp != NULL)
		{
			printf("%3d",temp->data);
			temp = temp->pred;
		}	
		printf("\n");
}
int main()
{
	dllNode *L,*R;
	L = R = NULL;	
	createDLL(&L,&R);
	duplicate(&L,&R);
	printLR(L);
	printRL(R);
}
