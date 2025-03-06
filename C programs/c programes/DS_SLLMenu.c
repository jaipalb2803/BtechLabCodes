#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int num;                   
    struct node *link;   
}NODE;
NODE* createList(NODE*start,int*m)
{
    printf("Enter the no of elements:");
    scanf("%d",m);
    NODE *temp;
    for(int i=1;i<=*m;i++)
    {
        NODE*new=(NODE*)malloc(sizeof(NODE));
        printf("enter data-%d=",i);
        scanf("%d",&new->num);
        new->link=NULL;
        if(start==NULL)
        {
            temp=start=new;                 
        }
        else
        {
            temp->link=new;
            temp=new;
        }
    }
    return(start);
} 
NODE* insertBeg(NODE*start)
{
    int n;
    NODE*new=(NODE*)malloc(sizeof(NODE));
    printf("Enter the insert elements:");
    scanf("%d",&new->num);
    new->link=start;
    start=new;
    return(start);

}
NODE* insertEnd(NODE*first)
{
    NODE* i;
    NODE*new=(NODE*)malloc(sizeof(NODE));
    printf("Enter the insert elements:");
    scanf("%d",&new->num);
    new->link=NULL;
    for(i=first;i->link!=NULL;i=i->link)
    {
           continue;
    }
    i->link=new;
    return first;
}
NODE*insertMid(NODE*first,int p)
{
    int n,i;
    NODE*new=(NODE*)malloc(sizeof(NODE)),*temp;
    printf("Enter the insert elements:");
    scanf("%d",&new->num);
    printf("enter the position:");
    scanf("%d",&n);
    new->link=NULL;
    temp=first;
    if(n<=p)
    {   
        for(i=1;i<n-1;i++)
        {
            temp=temp->link;
        }
        new->link=temp->link;
        temp->link=new;
    }
    else
    {
        printf("Position shouldn't in over list limit-%d:\n",p);
    }
    return first;
}
NODE*deleteBeg(NODE*first)
{
    NODE*temp;
    if(first==NULL)
    {
        free(first);
    }
    else
    {
        temp=first;
        first=first->link;
        free(temp);
    }
    return first;
}
NODE*deleteEnd(NODE*first)
{
    NODE*i;
    if(first==NULL)
    {
        free(first);
    }
    for(i=first;(i->link->link)!=NULL;i=i->link)
    {
           continue;
    }
    i->link=NULL;
    free(i->link->link);
    return first;
}
NODE*deleteMid(NODE*first,int p)
{
    int n,i;
    NODE*temp;
    printf("enter the position:");
    scanf("%d",&n);
    if(n<=p)
    {
        for(i=1,temp=first;i<n-1;i++,temp=temp->link)
        {
           continue;
        }
        temp->link=temp->link->link;
    }
    else
    {
        printf("Position shouldn't in over list limit-%d\n:",p);
    }
    return first;
}
int searchEle(NODE*first,int *p)
{
   NODE*i;
   int c;
   printf("Enter the search element=");
   scanf("%d",p);
   c=0;
   for(i=first;i!=NULL;i=i->link)
   {
         c++;
         if(*p==i->num)
         {
            break;
         }
   }
   if(i!=NULL&c>0)
   {
      return c ; 
   }
   else
   {
      return 0;
   }
}
NODE* reverseList(NODE*first)
{
    if(first==NULL)
        return first;
    else
     {
        NODE*cur,*pre=NULL,*next;
        cur=next=first;
        while (next!=NULL)
        {
            next=next->link;
            cur->link=pre;
            pre=cur;
            cur=next;

        }
        return pre;
     }

}
void printList(NODE*first)
{
     NODE* i;
     for(i=first;i!=NULL;i=i->link)
        {
            printf("%d\t", i->num);       
        }       
}
int main()
{
    int n,m;
    NODE*first=NULL;
    first=createList(first,&m);
    label0:printf("Choose the following option :\n1.insertion\n2.deletion\n3.searching\n4.Reverse\n");
    printf("enter your choice:");
    scanf("%d",&n);
    switch(n)
    {
        int x;
        label1:case 1:printf("Choose the following option :\n1.insert Begening\n2.insert End\n3.insert Mid\n");
               printf("enter your choice:");
               scanf("%d",&x);
               switch(x)
               {
                 case 1:first=insertBeg(first);
                        break;
                 case 2:first=insertEnd(first);
                        break;
                 case 3:first=insertMid(first,m);
                        break;
                 default:printf("Please enter the correct choice..!!\n");
                        goto label1;
               }
               break;
        label2 :case 2: printf("Choose the following option :\n1.Delete Begening\n2.Delect End\n3.Delect Mid\n");
               printf("enter your choice:");
                scanf("%d",&x);
                switch(x)
               {
                 case 1:first=deleteBeg(first);
                        break;
                 case 2:first=deleteEnd(first);
                        break;
                 case 3:first=deleteMid(first,m);
                        break;
                 default:printf("Please enter the correct choice..!!\n");
                        goto label2;
               }
               break;
        case 3:int c;
               c=searchEle(first,&x);
               (c!=0)?
                printf("%d is found at position=%d\nGiven list:",x,c):
                printf("%d is not found in below Given list:",x);
               break;
        case 4:first=reverseList(first);
               printf("reverse list:\n");
               break;
        default:printf("Please enter the correct choice..!!\n");
               goto label0; 
    }
    printList(first);
  
}
