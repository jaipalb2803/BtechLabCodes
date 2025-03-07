
#include<iostream>
#include<cstdlib>
using  namespace std;

typedef struct Process
{
    char ch;
    int p,At,Bt,Ct,Tat,Wt,Rt;
}pro;
void sort(pro a[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].p>a[j+1].p)
			{
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
    int n;
    scanf("%d",&n);
    int bt[n],t=0;
    pro a[n];
    char ch='A';
    for(int i=0;i<n;i++)
	{
        a[i].ch=ch;
        printf("Enter priority,at,bt of process %d=",i+1);
        scanf("%d%d%d",&a[i].p,&a[i].At,&a[i].Bt);
        t=t+a[i].Bt;
        ch++;
         bt[i]=a[i].Bt;
    }
    int gc=0;
    sort(a,n);    
    while(t>0)
	{
        for(int j=0;j<n;j++)
		{
            if(gc>=a[j].At && bt[j]>0)
			{
                if(a[j].Bt==bt[j])
                    a[j].Rt=gc-a[j].At;
                t--;
                bt[j]--;
                if(bt[j]==0)
                    a[j].Ct=gc+1;
                break;
            }
        }
        gc++;
    }
    sort_pro(a,n);
    float avgTat=0,avgWt=0;
	printf("processId\tpriorty\tAT\tBT\tCT\tTAT\tWT\tRt\n");
    for(int i=0;i<n;i++)
	{
        a[i].Tat=a[i].Ct-a[i].At;
        a[i].Wt=a[i].Tat-a[i].Bt;
        avgWt=avgWt+a[i].Wt;
        avgTat=avgTat+a[i].Tat;
        printf("%c\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i].ch,a[i].p,a[i].At,a[i].Bt,a[i].Ct,a[i].Tat,a[i].Wt,a[i].Rt);
    }
    printf("avgTat=%f\n",avgTat/n);
    printf("avgWt=%f",avgWt/n);
    return 0;
}