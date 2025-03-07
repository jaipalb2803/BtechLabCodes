#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
      int data;
      struct Node*L;
	  struct Node*R;
          
}node;
 void inOrder(node* root)
 {
 	if(root==NULL)
 			return ;				 
 	 inOrder(root->L);
 	 if(root->data!=0)
 	 	 printf("%d\t",root->data);
 	 inOrder(root->R);
 }
 node*  findNode( node*root,int k)
 {
 		node* temp=root;
			
		while(k!=temp->data)
		{
		        if(k<temp->data)
					temp=temp->L;
				else
				   temp=temp->R;				
		}
		return temp;
 }
node* deleteNode(node* root,int k)
{
			node* prev,*temp,*key=findNode( root, k);
			    temp=prev=key;
			   if(key->L!=NULL&&key->R!=NULL)
				{
                    temp=temp->R;
					while (temp->L!=NULL)
					{
						prev=temp;
						temp=temp->L;
					}
					if(root->data!=key->data)
					{
					  prev->R=temp->R;
					}
					else
					{
					  prev->L=NULL;
					}
					key->data=temp->data;
					free(temp);
					
				}
				else if(key->L!=NULL&key->R==NULL)
				{
					  temp=temp->L;
					while (temp->R!=NULL)
					{
						prev=temp;
						temp=temp->R;
					}
					if(root->data!=key->data)
					{
					  prev->R=temp->R;
					}
					else
					{
					  prev->R=temp->L;
					}
					key->data=temp->data;
					free(temp);
					
				}
				else if(key->L==NULL&key->R!=NULL)
				{
					temp=temp->R;
					while (temp->L!=NULL)
					{
						prev=temp;
						temp=temp->L;
					}
					if(root->data!=key->data)
					{
					  prev->R=temp->R;
					}
					else
					{
					  prev->L=NULL;
					}
					key->data=temp->data;
					free(temp);

				}
				else
				{
					temp=root;
					while(key->data!=temp->data)
					{
                        prev=temp;
		        		if(k<temp->data)
						  temp=temp->L;
						else
				   		  temp=temp->R;				
					}
					if(k<prev->data)
					{
				       prev->L=NULL;
					}
				    else
				    {
				       prev->R=NULL;
					}
				}
			return root;
			
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
 };
int main()
{
      int n;
      printf("Enter the no of node ?:");
      scanf("%d",&n);
      node* root=NULL;
      root=createBinSrchTree(root,n); 
      inOrder(root);
      printf("\nEnter element have to delete:");
      int k;
      scanf("%d",&k);
      root=deleteNode(root,k);
      inOrder(root);
	
	  
}