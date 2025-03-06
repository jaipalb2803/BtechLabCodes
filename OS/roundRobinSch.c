#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1;
typedef struct Process{
    char ch;
    int At,Bt,Ct,Tat,Wt,Rt;
}pro;
pro* dequeue(pro* q[],int n)
{
    int temp=front;
    if (rear==temp)
    {
        front=rear=-1;
        return q[temp];
    }
    front=(front+1)%n;
    return q[temp];
}
void enqueue(pro* q[],int n,pro* P)
{
    if(front==-1)
        front=(front+1)%n;
    rear=(rear+1)%n;
    q[rear]=P;
}
void sort(pro a[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].At>a[j+1].At){
                pro temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}
void sort_pro(pro a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].ch>a[j+1].ch){
                pro temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
         }
}
int main()
{
    printf("Enter no.of processes:");
    int n,tq;
    scanf("%d",&n);
    printf("Enter Time quantum=");
    scanf("%d",&tq);
    if(tq<1){
        printf("Time quantum must be >1.");
        return 0;
    }
    int t=0,bt[n];
    pro a[n];
    char ch='A';
    for(int i=0;i<n;i++)
    {
        a[i].ch=ch;
        printf("Enter at,bt of process %d=",i+1);
        scanf("%d%d",&a[i].At,&a[i].Bt);
        t=t+a[i].Bt;
        ch++;
        bt[i]=a[i].Bt;
    }
    int gc=0,*visit=(int *)calloc(n,sizeof(int));
    sort(a,n);
    pro* queue[n],*pt;
    while(t>0)
    {
        for(int i=0;i<n;i++)
            if((gc+tq)>=a[i].At && visit[i]==0)
            {
                enqueue(queue,n,&a[i]);
                visit[i]=1;
            }
        if(front!=-1 && gc>=(queue[front]->At))
        {
            pt=dequeue(queue,n);
            int index=(pt->ch)%65;

            if((pt->Bt)==bt[index])
                pt->Rt=gc-(pt->At);
    
            if(bt[index]<=tq)
            {
                gc+=bt[index];
                t-=bt[index];

                pt->Ct=gc;
                bt[index]=0;
            }
            else
            {
                bt[index]-=tq;
                t-=tq;

                gc+=tq;
                enqueue(queue,n,pt);
            }
        }
        else
            gc++;
    }
    sort_pro(a,n);
    float avgTat=0,avgWt=0;
    printf("processId\tAT\tBT\tCT\tTAT\tWT\tRt\n");
    for(int i=0;i<n;i++)
    {
        a[i].Tat=a[i].Ct-a[i].At;
        a[i].Wt=a[i].Tat-a[i].Bt;
        avgTat=avgTat+a[i].Tat;
        avgWt=avgWt+a[i].Wt;
        printf("%c\t\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].ch,a[i].At,a[i].Bt,a[i].Ct,a[i].Tat,a[i].Wt,a[i].Rt);
    }
    printf("avgTat=%f\n",avgTat/n);
    printf("avgW t=%f",avgWt/n);
    return 0;
}