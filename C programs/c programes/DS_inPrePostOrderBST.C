#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *left, *right;
}node;

node* newNode(int ele)
{
	node* temp= (node*)malloc(sizeof(node));
	temp->data = ele;
	temp->left = temp->right = NULL;
	return temp;
}
void preorder( node* root)
{
	if (root==NULL)
	{
		 return;
	}
	else if(root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder( node* root)
{
	if (root==NULL)
	{
		 return;
	}
	else if(root != NULL)
	{
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
void postorder( node* root)
{
	if (root==NULL)
	{
		 return;
	}
	else if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}

node* insertInBST( node* root, int key)
{
	if (root== NULL)
		return newNode(key);

	if (key < root->data)
		root->left = insertInBST(root->left, key);
	else if (key > root->data)
		root->right = insertInBST(root->right, key);

	return root;
}
int main()
{
	int n;
	node* root = NULL;
	printf("Enter the no of elements in BST?:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int ele;
		printf("Enter the ele-%d= ",i);
		scanf("%d",&ele);
		if(i==1)
			root = insertInBST(root, ele);
		else
             insertInBST(root, ele);

	}

	printf("\n");

	printf("\nBST in preorder : ");
	preorder(root);

    printf("\nBST in  Inorder : ");
	inorder(root);

 	printf("\nBST in postorder: ");
	postorder(root);

	printf("\n");
}