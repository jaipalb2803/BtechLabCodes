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
int getLast(Node*first,int k,int n)
{
    for(int i=k;i<=n-1;i++)
    {           
        first=first->link;
    }
    first->data;
    return(first->data);
    
}
int main()
{
    int n,c;
    Node*first,*ptr;
    first=NULL;
    printf("Enter the no of nodes=");
    scanf("%d",&n);
    printf("Enter the date in List\n");
    first=creatList(first,n); 
    printList(first);
    c=0;
    ptr=first;
    for(int i=1;i<=(n/2);i++)
    {    
        if(first->data==getLast(ptr,i,n))
            c++;
        else
            break;
        first=first->link;
    }
    (c==(n/2))?printf("\nGiven list is PALIMDROM"):
     printf("\nGiven list is NOT PALIMDROM");

}