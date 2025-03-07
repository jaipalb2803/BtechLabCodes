#include<stdio.h>
#include<stdlib.h>
#define MAX 20
 struct node
{
    int data;
    struct node* lc;
    struct node* rc;
}*root;
struct node* stk[MAX];
int top=-1;
struct node* stk1[MAX];
int top1=-1;
struct node* stk2[MAX];
int top2=-1;
struct node* topele1()
{
    return stk1[top1];
}
struct node* topele2()
{
    return stk2[top2];
}
struct node* topele()
{
    return stk[top];
}
void push(struct node* temp)
{
    stk[++top]=temp;
}
void push1(struct node* temp)
{
    stk1[++top1]=temp;
}
void push2(struct node* temp)
{
    stk2[++top2]=temp;
}
struct node* pop1()
{
    return stk1[top1--];
}
struct node* pop2()
{
    return stk2[top2--];
}
struct node* pop()
{
    return stk[top--];
}
void pre_order()
{
    push(NULL);
    struct node* temp=root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        if(temp->rc!=NULL)
            push(temp->rc);
        if(temp->lc!=NULL)
            temp=temp->lc;
        else
            temp=pop();
    }
    top=-1;
}                            
void in_order()
{                                                           
    struct node* temp=root;                                                                                                                                                                       
    push(NULL);                     
    push1(NULL);                                                                                 
    while(temp!=NULL)
    {
        if(temp->rc!=NULL && temp->rc!=topele())                                  
            push(temp->rc);
        if(temp->lc==NULL||temp->lc==topele1())
        {
            if(temp->lc!=NULL) pop1();
            printf("%d ",temp->data);
            temp=pop();
        }              
        else
        {
            push(temp);
            push1(temp->lc);
            temp=temp->lc;
        }               
    }
    top=-1;
    top1=-1;
}
void post_order()
{
    struct node* temp=root;
    push(NULL);
    push1(NULL);
    push2(NULL);
    while(temp!=NULL)
    {
        if((temp->lc==NULL||temp->lc==topele1()) && (temp->rc==NULL||temp->rc==topele2()))
        {
            if(temp->lc!=NULL)  pop1();
            if(temp->rc!=NULL)  pop2();
            printf("%d ",temp->data);
            temp=pop();
        }
        if(temp==NULL) break;
        if(temp->rc!=NULL && temp->rc!=topele2())
        {
            push(temp);
            push(temp->rc);
            push2(temp->rc);
            if(temp->lc==NULL) temp=pop();
        }
        if(temp->lc!=NULL&&temp->lc!=topele1())
        {
            if(temp->rc==NULL) push(temp);
            push1(temp->lc);
            temp=temp->lc;
        }
        
    }
    top=-1;
    top1=-1;
    top2=-1;
}
void create()
{
    struct node*nn,*temp,*par;
    while(1)
    {
        int d;
        scanf("%d",&d);
        if(d==-1)
            break;
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=d;
        nn->lc=NULL;
        nn->rc=NULL;
        if(root==NULL)
            root=nn;
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                par=temp;
                if(nn->data>temp->data)
                    temp=temp->rc;
                else
                    temp=temp->lc;
            }
            if(par->data<nn->data)
                par->rc=nn;
            else    
                par->lc=nn;
        }
    }
}
void main()
{
    printf("enter elements and -1 to stop: ");
    create();
    printf("preorder: ");
    pre_order();
    printf("\ninorder: ");
    in_order();
    printf("\npostorder: ");
    post_order();
}