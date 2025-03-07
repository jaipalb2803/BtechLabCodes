#include<stdio.h>
typedef struct process
{
    char p;
    int At,Bt,Ct,Tat,Wt;
}P;
void sort(int n,P a[])
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].At>a[j+1].At)
            {
                P temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}
void sort_pro(P a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].p>a[j+1].p){
                P temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
         }
}
int main(){
    int n;
    char ch='A';
    printf("Enter no.of processes:");
    scanf("%d",&n);
    P a[n];
    for(int i=0;i<n;i++)
    {
        a[i].p=ch;
        printf("Enter the arrival time and burst time=");
        scanf("%d%d",&a[i].At,&a[i].Bt);
        a[i].Ct=-1;
        ch++;
    }
    int gc=0;
    sort(n,a);
    int k;
    for(int j=0;j<n;j++)
    {
        k=1;
        if(a[j].Ct==-1 && gc>=a[j].At)
        {
            gc=gc+a[j].Bt;
            a[j].Ct=gc;
            k=0;
        }
        if(k==1)
        {
            gc=a[j].At;
            j--;
        }
    }
    sort_pro(a,n);
    float avgTat=0,avgWt=0;
    printf("Pid  AT  BT  CT TAT WT\n");
    for(int i=0;i<n;i++){
        a[i].Tat=a[i].Ct-a[i].At;
        avgTat=avgTat+a[i].Tat;
        a[i].Wt=a[i].Tat-a[i].Bt;
        avgWt=avgWt+a[i].Wt;
        printf("%c   %d    %d    %d    %d   %d\n",a[i].p,a[i].At,a[i].Bt,a[i].Ct,a[i].Tat,a[i].Wt);
    }
    printf("avgTat=%f\n",avgTat/n);
    printf("avgWT=%f",avgWt/n);
    return 0;
}