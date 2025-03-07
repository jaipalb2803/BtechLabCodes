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
Node* margeAlter(Node**first,Node**second,int n1,int n2)
{
    Node*temp,*ptr,*start=*first;
    for(int i=1;(i<=n1)&(i<=n2);i++)
    {
        
            temp=*second;
            ptr=*first;

            *first=(*first)->link;
            *second=(*second)->link;

            temp->link=ptr->link;
            ptr->link=temp;

    }
    ptr->link->link=NULL;
     return(start);
    
}
void printList(Node*first)
{
    if(first==NULL)
       printf("NULL");
    while(first)
    {
        printf("%5d",first->data);
        first=first->link;
    }
}
int main()
{
    int n1,n2;
    Node*first,*second,*start;
    first=NULL;
    second=NULL;
    printf("Enter the no of nodes=");
    scanf("%d",&n1);
    printf("Enter the date in first List\n");
    first=creatList(first,n1);  
    printf("Enter the no of nodes=");
    scanf("%d",&n2);
    printf("Enter the date in second List\n");
    second=creatList(second,n2);
    start=margeAlter(&first,&second,n1,n2); 
    printf("after alternate insertion:");
    printList(start);
    if(n1>n2)
    {
        printf("\nremain element after alternate insertion:");
        printList(first);
    }
    else
    {
        printf("\nremain element after alternate insertion:");
        printList(second);
    }
      

}