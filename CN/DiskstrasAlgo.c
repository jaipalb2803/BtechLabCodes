#include<stdio.h>
#include<conio.h>
#define INFINITY 9999

void readAdjMat(int n,int G[][n])
{
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
        scanf("%d",&G[i][j]);
} 
void createCostMat(int n,int G[][n],int C[][n])
{
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         if(G[i][j]==-1)
            C[i][j]=INFINITY;
         else
            C[i][j]=G[i][j];
}
void dijkstra(int n,int G[][n],int start)
{
 
   int cost[n][n],distance[n],pred[n];
   int visited[n],count,min,next,i,j;
   //pred[] stores the predecessor of each node
   //count gives the number of nodes seen so far
   createCostMat(n,G,cost);
   //initialize pred[],distance[] and visited[]
   for(i=0;i<n;i++)
   {
     distance[i]=cost[start][i];
     pred[i]=start;
     visited[i]=0;
   }
   distance[start]=0;
   visited[start]=1;
   count=1;
   while(count<n-1)
   {
     min=INFINITY;
     //nextnode gives the node at minimum distance
     for(i=0;i<n;i++)
        if(distance[i]<min&&!visited[i])
        {
            min=distance[i];
            next=i;
        }
     //check if a better path exists through nextnode 
     visited[next]=1;
     for(i=0;i<n;i++)
        if(!visited[i])
            if(min+cost[next][i]<distance[i])
            {
                distance[i]=min+cost[next][i];
                pred[i]=next;
            }
      count++;
    }
    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=start)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=start);
        }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t",pred[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t",visited[i]);
     printf("\n");   
     for(i=0;i<n;i++)
        printf("%d\t",distance[i]);
    printf("\n");
}
int main()
{
    int n;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int G[n][n],s;
    printf("\nEnter the adjacency matrix:\n");
    readAdjMat(n, G);
    start:
        printf("\nEnter the starting node:");
        scanf("%d",&s);
        dijkstra(n,G,s);
    goto start;
    return 0;
}
 
