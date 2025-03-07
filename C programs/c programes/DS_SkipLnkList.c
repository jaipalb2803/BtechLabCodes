#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct  node *link;
	struct  node *skiplink;

}node;

void createSkipList(node**first,int n)
{
	node*new,*temp,*midptr;
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter ele[%d]=",i+1);
		new=(node*)malloc(sizeof(node));
		scanf("%d",&new->data);
		new->link=NULL;
		if(*first==NULL)
		{
			*first=temp=new;
		}
		else
		{
			if(i==n/2+1)
			{
                (*first)->skiplink=temp;
				 midptr=temp;
			}
			temp->link=new;
			temp=new;
			
		}
	}
  if(i>2)
  {
    midptr->skiplink=temp;
	temp->skiplink=NULL;
  }
}
void printList(node*first)
{
	if(first==NULL)
	{
		printf("LIST IS EMPTY");
		//exit(0);
	}
	else
	{   node*temp=first;
		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			temp=temp->skiplink;
		}		
	}
}
int searchEle(node*first,int k,int n)
{
	 int c=1,flag=0,mid=0;
	 if(n!=1)
	   mid=first->skiplink->data;
     while(first)
	 {
	     if(k==first->data)
		     return c;
		 else if(k>mid && c==0)
		 {
			if(n==1)
			{
			    return -1;
			}
		 	 first=first->skiplink;
			 c=n/2;
		 }
	     else
	    	flag=1;

		 first=first->link;
		 c++;
	 }
	 if(flag==1)
	   return -1;
}
int main()
{
	node*first;
	first=NULL;
	int n,k;
	printf("Enter no of nodes?:");
	scanf("%d",&n);

	createSkipList(&first,n);
	printf("LIST IS:");
	printList(first);
	 
    printf("\nEnter your key:");
    scanf("%d",&k);
	n=searchEle(first,k,n);

	(n!=-1)?printf("key-%d found at postion=%d",k,n):
	printf("key-%d not found in List",k);
}
