#include <stdio.h>
#include <stdlib.h>

void push(int stack[],int node,int *top)
{
    stack[++(*top)] = node;
}
int pop(int stack[],int *top) 
{
    return stack[(*top)--];
}
void dfs(int s, int n,int a[][n])
{
    int *visit =(int*)calloc(n,sizeof(int));
    int stk[n], top = -1;
    push(stk,s,&top);
    visit[s] = 1;

    while (top != -1) 
	{
        int curr = pop(stk,&top);
		printf("%d ",curr);
        for (int i = n-1; i >=0; i--) 
		{
            if (a[curr][i] && !visit[i])
			 {
                push(stk,i,&top);
                visit[i] = 1;               
            }
        }
    }
}
void  readGraph(int n,int edg,int a[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	         a[i][j]=0;
	    }
	}
	for(int k=1;k<=edg;k++)
	{
	       printf("Enter the V(i,j) of edge-%d :",k);
	       scanf("%d%d",&i,&j);
	       a[i][j]=a[j][i]=1;
	}
}
void printGraph(int n,int a[][n])
{
 	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	         printf("%3d",a[i][j]);
	    }
	    printf("\n");
	}
}
int main()
{
    int n, edg;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edg);
    int a[n][n];

	printf("Enter the edges (in the format u v):\n");
    readGraph(n,edg,a);

    printf("Graph in AdjMatrix:\n");
    printGraph(n,a);
    // run DFS from start node
    start: int s,c;
           printf("Enter the starting node: ");
           scanf("%d", &s);
           printf("DFS traversal: ");
           dfs(s, n,a);
           printf("\nEnter opt:\n1.repeat\n2.exit\n<=");
           scanf("%d",&c);
	       if(c==1)
	       {
		     goto start;
	       } 		


    return 0;
}
