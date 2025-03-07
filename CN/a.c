// A C program to obtain a broadcast tree for a subnet using Prim's algorithm

#include <stdio.h>
#define INFINITY 99999

typedef struct node
{
    int cost, path;
}host;
void readAdjMat(int n,int G[][n])
{
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
        scanf("%d",&G[i][j]);
} 
int findMinCostIndex(int n, host H[],int visited[])
{
    int min = INFINITY,index;

    for (int i= 0; i<n;i++)
        if (visited[i]==0 && H[i].cost< min)
        {
            min = H[i].cost;
            index=i;
        }
    return index;
}
int sumOfAllMinCost(int n,host H[])
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=H[i].cost;
    return sum;
}
void printBroadcastTree( int n,host H[])
{
    printf("Edge \tWeight\n");
    for (int i = 0; i < n; i++)
      if(H[i].path>=0)
        printf("%d - %d \t%d \n", H[i].path, i,H[i].cost);
}
void primMST(int n,int s,int G[n][n],host H[])
{
    int visited[n];

    for (int i= 0; i<n;i++)
    {
        H[i].cost =INFINITY;
        visited[i]=0;
    }
    H[s].cost= 0;
    H[s].path=-1; 

    for (int i= 0; i < n; i++)
    {
        int u =findMinCostIndex(n,H,visited);
        visited[u] = 1;
        for (int v = 0; v < n; v++)
          if (G[u][v] && visited[v]==0 && G[u][v] < H[v].cost)
                H[v].path= u , H[v].cost= G[u][v];
    }
}
int main()
{
    
    int n,sum=0;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int G[n][n],s;
    printf("\nEnter the adjacency matrix:\n");
    readAdjMat(n,G);
    host H[n];
    label:
      printf("\nEnter the starting node:");
      scanf("%d",&s);
      primMST(n,s,G,H);
      sum=sumOfAllMinCost(n,H);
      printf("\nMinimium Spanning cost:%d\n",sum);
      printBroadcastTree(n,H);
    goto label;
    return 0;
}
