#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*left;
	struct Node*right;	
};

typedef struct Node node;

node* createBinTree(void)
{
    int x;
	node *new;
	new=(node*)malloc(sizeof(node));
	node* root=new;
	printf("\nEnter data(0 for null node):");
	scanf("%d",&x);
	if(x==0)
	{
		return 0;
	}
	new->data=x;
	printf("Enter the left-child of %d",x);
	new->left=createBinTree();
	printf("Enter the right-child of %d",x);
	new->right=createBinTree();

	return root;
}
void printBinTree(node*root)
{ 
		printf("%5d",root->data);
		if(root->left==root->right)
		{
			return;
		}
		else if(root->left!=NULL && root->right!=NULL)
		{
            printBinTree(root->left);
		    printBinTree(root->right);
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			printBinTree(root->right);
		}
		else if(root->left!=NULL && root->right==NULL)
		{
            printBinTree(root->left);
		}
		
}
int main()
{
	int n; 
	node *root=NULL;
	root=createBinTree();
	printf("BINARY TREE IS:");
	if(!root)
	{
		printf("TREE WITH NULL DATA");
	}
	else
	{
	   printBinTree(root);
	}
}
