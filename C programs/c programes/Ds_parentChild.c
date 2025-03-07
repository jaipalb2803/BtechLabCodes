#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
      int data;
      struct Node*L;
	  struct Node*R;
          
}node;

void nextLevel(node*Lroot,node*Rroot)
{

    void printLevel(node*root);

     if(Lroot==NULL&&Rroot==NULL)
     {
         return;
     }
     else
     {
         printf("%d\t",Lroot->data);
         printf("%d\t",Rroot->data);
     }     
    if(Lroot->R!=NULL&&Lroot->L!=NULL)
    {      
        nextLevel(Lroot->L,Lroot->R);
    }
    else if(Lroot->R==NULL&&Lroot->L==NULL)
    {    
       
        return;
    }
    else
    {   
        (Lroot->L==0)?printLevel(Lroot->R):printLevel(Lroot->L);
    }
    if(Rroot->R!=NULL&&Rroot->L!=NULL)
    { 
        nextLevel(Rroot->L,Rroot->R);
    }
    else if(Rroot->R==NULL&&Rroot->L==NULL)
    {    
        
        return;
    }
    else
    {    
        (Rroot->L==0)?printLevel(Rroot->R):printLevel(Rroot->L);
    }
    

     
}
void printLevel(node*root)
{
     
       printf("%d\t",root->data);

     if(root->R!=NULL&&root->L!=NULL)
        nextLevel(root->L,root->R);
     else  if(root->R==NULL&&root->L==NULL)
       return;
     else  if(root->R==NULL&&root->L!=NULL)
       printLevel(root->L);
     else
       printLevel(root->R);
    

}
node* createBinSrchTree(node*root,int n)
 {
 	node *temp,*prev,*new;
 	for(int i=1; i<=n; i++)
 	{
 		new=(node*)malloc(sizeof(node));
 		printf("Enter the element -%d= ",i);
 		scanf("%d",&new->data);
 		new->L=new->R=NULL;
 		
 		if(root==NULL)
 		{
 		    root=new;
		}
		else
		{
				while(temp)
				{
					prev=temp;
				    if(new->data <temp->data)
				       	temp=temp->L;
				    else
				       	temp=temp->R;
				}
				 if(new->data <prev->data)
				    prev->L=new;
				 else
				    prev->R=new;
		}
		temp=root;
	}
	return root;
 }
int main()
{
     int n;
      printf("Enter the no of node ?:");
      scanf("%d",&n);
      node* root=NULL;
      root=createBinSrchTree(root,n); 
       
      printLevel(root);

}