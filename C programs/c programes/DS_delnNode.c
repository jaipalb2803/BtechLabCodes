#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}Node;

Node* creatList(Node*first,int n)
{
    int i;
    Node*new,*temp;
    for(i=1;i<=n;i++)
    {
        new=(Node*)malloc(sizeof(Node));
        printf("enter data-%d=",i);
        scanf("%d",&new->data);
        new->link=NULL;
        if(first==NULL)
        {
            first=temp=new;
        }
        else
        {
            temp->link=new;
            temp=new;
        }      
    }
    return(first);
}
void printList1(Node*first)
{
    if(first==NULL)
       printf("NULL");
    while(first->link)
    {
        printf("%5d",first->data);
        first=first->link;
    }
}
void printList2(Node*first)
{
    if(first==NULL)
       printf("NULL");
    while(first)
    {
        printf("%5d",first->data);
        first=first->link;
    }
}
void deleteNode(Node**first,int n)
{
    Node*temp;
    for(int i=0;(i<n)&(*first)->link!=NULL;i++)
    { 
        *first=(*first)->link;
    }
}
int main()
{
    int n,M,N,c;
    Node*first,*ptr,*temp;
    first=NULL;
    printf("Enter the no of nodes=");
    scanf("%d",&n);
    printf("Enter the date in List\n");
    first=creatList(first,n); 
    printf("Enter the value of M:");
    scanf("%d",&M);
    printf("Enter the value of N:");
    scanf("%d",&N); 
    ptr=first;
    c=0; 
    while(first!=NULL)
    {
        if(c==M)
        {
            deleteNode(&first,N);
            temp->link=first;
            c=0;
        }
        c++;
        temp=first;
        first=first->link;
    }
    printf("After the deletion of list:");
    if(M%2==0)
       printList1(ptr);
    else
       printList2(ptr);
    
}