#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	 int data;
	  struct node*prev;
	  struct node*nxt;
}dllNode;

void insertLeftMost(dllNode ***Lf,dllNode***Rt,int i)
{
		dllNode*new;
		new=(dllNode*)malloc(sizeof(dllNode));
		printf("enter data-%d=",i);
		scanf("%d",&new->data);
		if(**Lf==NULL)
		{
				new->nxt=new->prev=NULL;
				**Lf=**Rt=new;
		}
		else
		{
				new->nxt=**Lf;
				new->prev=NULL;
				
				(**Lf)->prev=new;
				**Lf=new;
		}
}
void  printLR(dllNode**Lf)
{
			dllNode *temp;
			temp=*Lf;
			if(temp==0)
					printf("NULL");
			else
				while(temp)
				{
						printf("%5d",temp->data);
						temp=temp->nxt;
				}
}
void  printRL(dllNode**Rt)
{
			dllNode *temp;
			temp=*Rt;
			if(temp==0)
					printf("NULL");
			else
				while(temp)
				{
						printf("%5d",temp->data);
						temp=temp->prev;
				}
}
void creatDllNode(dllNode**Lf,dllNode**Rt,int n)
{
               printf("Enter %d nodes in list:\n",n);
				for(int i=1;i<=n;i++)
				{
						insertLeftMost(&Lf,&Rt,i);
				}
}
int searchEle(dllNode**Lf,int ele)
{
		 dllNode*i;
		 int c=0;
		 for(i=*Lf;i!=NULL;i=i->nxt)
		 {
		 		c++;
		 		 if(ele==(i->data))
		 		 			break;
		 }
		 return c;
}
void deleteElement(dllNode**Lf,int n)
{
		dllNode*temp=*Lf,*ptr;
		for(int i=1;i<n-1;i++)
		  	temp=temp->nxt;
		  		
		  ptr=temp->nxt->nxt;
		  temp->nxt=ptr;
		  ptr->prev=temp;
		 
		
}
int main()
{
		dllNode *Lf=NULL,*Rt=NULL;
		int n;
		printf("enter no of Nodes:");
		scanf("%d",&n);
		creatDllNode(&Lf,&Rt,n);
		
		printf("your list of double  nodes form left:");
		printLR(&Lf);
		
		printf("\nyour list of double  nodes form right:");
		printRL(&Rt);
		
		int ele,count,del;
		printf("\nEnter search element:");
		scanf("%d",&ele);
		count=searchEle(&Lf,ele);
		printf("\n%d element found at %d position from Left",ele,count);
		
		printf("\nEnter the which element need to delete:");
		scanf("%d",&del);
		deleteElement(&Lf,del);
		printf("\nAfter deletion of %d in list:",del);
		printRL(&Lf);

}
/*
typedef struct node
{
    int data;
    struct node *pre,*succ;

}node;

void createDLL(node**F,node**R,int n)
{
    for(int i=0;i<n;i++)
    {
        node *new=(node*)malloc(sizeof(node));
        new->pre=new->succ=NULL;

        printf("Enter the data-%d=",i+1);
        scanf("%d",&new->data);

        if(*F==NULL)
        {
            *F=*R=new;
        }
        else
        {
            (*R)->succ=new;
            new->pre=*R;
            *R=new;
        }
    }
}
void printDLL(node*start)
{
    node*temp=start;
    int c;
    c=(temp->pre==0)?1:0;
    
    while(temp)
    {
        printf("%3d",temp->data);
        temp=(c==1)?temp->succ:temp->pre;
    }
}
int main()
{
    node *F=NULL,*R=NULL;
    int n;
    printf("Enter the no.of nodes=");
    scanf("%d",&n);

    createDLL(&F,&R,n);
    printf("From R->L:");
    printDLL(F);

    printf("\nFrom L->R:");
    printDLL(R);
   
}

*/