#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *link;

}node;

typedef struct Graph
{
    int Vertice;
    struct node**adjLists;
    int *visit;

}Graph;

Graph* createGraph(int v)
{
    Graph *graph = malloc(sizeof(struct Graph));
    graph->Vertice = v;
 
    graph->adjLists = calloc(v , sizeof(node*));
    //graph->visit = (int*)calloc(v , sizeof(int));
 
    return graph;
}
node *createNode(int v)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = v;
    new->link = NULL;
    return new;
}
void travDFS(Graph* gph, int s) 
{
  node* adjList = gph->adjLists[s];
  node* temp = adjList;

  gph->visit[s] = 1;
  printf("%3d", s);

  while (temp != NULL) 
  {
    int connectVtx = temp->data;

    if (gph->visit[connectVtx] == 0)
	{
      travDFS(gph, connectVtx);
    }
    temp = temp->link;
  }
}
void addEdge(Graph *graph, int s, int d)
{
	

    node*new = createNode(d);
    new->link = graph->adjLists[s];
    graph->adjLists[s] = new;

	new = createNode(s);
    new->link= graph->adjLists[d];
    graph->adjLists[d] = new;
 
    
}
void readGraph(Graph* g ,int n)
{
    int u,v;
    for(int i=0;i<n;i++)
    {
        printf("Enter no of E(u,v) of vetex-%d :",i+1); 
        scanf("%d %d",&u,&v);
		addEdge(g, u, v);           
        
    }
    
}
void printGraph(Graph* g,int n)
{
    for(int i=0;i<n;i++)
    {
        
        node*first=g->adjLists[i];
		printf("Node of V[%d] =>",i);
        if (first==NULL)
        {
            printf("  0 ");
        }
        else
        {
            while(first)
            {
                printf("%3d",first->data);
                first=first->link;
            }
        }
       printf("\n"); 
         
    }   

}
int main(void)
{
    
	int n;
    printf("Enter the no of edges=");
    scanf("%d",&n);
    int v[n];
    Graph* graph = createGraph(n);
    
    readGraph(graph,n);

	printGraph(graph,n);

    int s,c=1;
    while (c==1)
	{
		printf("Enter the start node=");
        scanf("%d",&s);
		graph->visit = (int*)calloc(n , sizeof(int));
        travDFS(graph,s);
        printf("\nEnter option:\n1.Repeat\n2.exit\n<=");
        scanf("%d",&c);
	       
	}
	       

}
