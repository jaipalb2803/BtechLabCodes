#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}Node;
void creatList(Node**first,int n)
{
    int i;
    Node*new;
    for(i=1;i<=n;i++)
    {
        new=(Node*)malloc(sizeof(Node));
        printf("enter data-%d=",i);
        scanf("%d",&new->data);
        if(*first==NULL)
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
}
void printList(Node**first)
{
    
    while(*first)
    {
        printf("%5d",(*first)->data);
        *first=(*first)->link;
    }

}
int main()
{
    int n;
    Node*first=NULL;
    printf("Enter the no of nodes=");
    scanf("%d",&n);
    printf("Enter the date in List\n");
    creatList(&first,n);   
    printList(&first);
}