#include<stdio.h>
#define N 64
typedef struct node {
	unsigned dist[N];
	unsigned from[N];
}Router;
void readDistMat(int n,int M[][n],Router R[])
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
         scanf("%d",&M[i][j]);
         if(i==j) M[i][j]=0;
         R[i].dist[j]=M[i][j];
         R[i].from[j]=j; 
       }
   }
}
void vectorRouting(int n,int M[][n],Router R[])
{
   int count;
   do{ 
      count=0;
		for(int i=0;i<n;i++)
		 for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			if(R[i].dist[j]>M[i][k]+R[k].dist[j]) 
         {
				R[i].dist[j]=R[i].dist[k]+R[k].dist[j];
				R[i].from[j]=k;
				count++; 
         }
	}while(count!=0);
}
void DisplayShrtDist(int n,int m[][n],Router R[])
{
    for(int i=0;i<n;i++)
   {
       printf("Router-%d\n",i+1);
       for(int j=0;j<n;j++)
       {
          printf("Node:%d Via:%d Dist:%d\n",j+1,R[i].from[j]+1,R[i].dist[j]);
       }
       printf("\n");
   } 
}
int main()
{
    int n;
    printf("Enter total no.of router=");
    scanf("%d",&n);
    Router rt[n];
    int M[n][n];
    printf("Enter a distance matric:\n");
    readDistMat(n,M,rt);
    vectorRouting(n,M,rt);
    printf("\nState value of each Router:\n");
    DisplayShrtDist(n,M,rt);
}