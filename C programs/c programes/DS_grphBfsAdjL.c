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
    Graph *graph = malloc(sizeof(Graph));
    //graph->Vertice = v;
 
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
int isEmpty(node *q)
{
    return q == NULL;
}
void enqueue(node **q, int val)
{
    node *new= createNode(val),*temp;
    if (isEmpty(*q))
    {
        *q=temp=new;
    }
    else
    {
        temp->link = new;
		temp=new;
    }
} 
int dequeue( node **Q)
{
    int val = (*Q)->data;
    node *temp = *Q;

    *Q = (*Q)->link;
    free(temp);

    return val;
}
/*void printQueue( node *Q)
{
    while (Q)
    {
        printf("%d ", Q->vertex);
        Q=Q->link;
    }
    printf("\n");
}*/
void travBFS(Graph *g,int v, int s)
{
    node *Q = NULL;
	g->visit = (int*)calloc(v , sizeof(int));
    g->visit[s] = 1;
    enqueue(&Q, s);
 
    while (!isEmpty(Q))
    {
        //printQueue(Q);
        int curVtx = dequeue(&Q);
        printf("%3d ", curVtx);
 
        node* temp = g->adjLists[curVtx];
 
        while (temp)
        {
            int adjVtx = temp->data;
 
            if (g->visit[adjVtx] == 0)
            {
                g->visit[adjVtx] = 1;
                enqueue(&Q, adjVtx);
            }
            temp = temp->link;
        }
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
int main(void)
{
    
	int n,edg;
    printf("Enter the no of vertices=");
    scanf("%d",&n);
    printf("Enter the number of edges: ");
    scanf("%d",&edg);
    int v[n];
    Graph* graph = createGraph(n);
    
    readGraph(graph,edg);

	printGraph(graph,n);

    int s,c=1;
    while (c==1)
	{
		printf("Enter the start node=");
        scanf("%d",&s);
        travBFS(graph,n,s);
        printf("\nEnter option:\n1.Repeat\n2.exit\n<=");
        scanf("%d",&c);
	       
	}
	
          

}
