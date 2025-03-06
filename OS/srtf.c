#include<stdio.h>
typedef struct process{
    char p;
    int At,Bt,Ct,Tat,Wt,Rt;
}P;
void sort(int n,P a[]){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j].Bt>a[j+1].Bt){
                P temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            else if((a[j].Bt==a[j+1].Bt) && (a[j].At>=a[j+1].At)){
                if((a[j].At==a[j+1].At)&&(a[j].p<a[j+1].p))
                    break;
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
    int n,t=0,total_Tat=0,total_Rt=0,total_Wt=0;
    char ch='A';
    printf("Enter no.of processes:");
    scanf("%d",&n);
    P a[n];
    for(int i=0;i<n;i++){
        a[i].p=ch;
        printf("Enter the arrival time and burst time=");
        scanf("%d%d",&a[i].At,&a[i].Bt);
        a[i].Ct=-2;
        ch++;
        t=t+a[i].Bt;
    }
    int gc=0;
    int bt[n];
    for(int i=0;i<n;i++)
        bt[i]=a[i].Bt;
    sort(n,a);
    while(t>0){
        int j=1;
        for(int i=0;i<n;i++){
            if(gc>=a[i].At && a[i].Bt>0){
                if(a[i].Ct==-2){
                    a[i].Rt=gc-a[i].At;
                    a[i].Ct=-1;
                }
                gc++;
                a[i].Bt--;
                if(a[i].Bt==0)
                    a[i].Ct=gc;
                t--;
                j=0;
                break;
            }
        }
        if(j==1)
            gc++;
        else
            sort(n,a);
    }
    sort_pro(a,n);
    for(int i=0;i<n;i++)
        a[i].Bt=bt[i];
    for(int i=0;i<n;i++){
        a[i].Tat=a[i].Ct-a[i].At;
        a[i].Wt=a[i].Tat-a[i].Bt;
        total_Rt+=a[i].Rt;
        total_Tat+=a[i].Tat;
        total_Wt+=a[i].Wt;
        printf("P%d     %d    %d    %d    %d   %d    %d\n",i+1,a[i].At,a[i].Bt,a[i].Ct,a[i].Tat,a[i].Wt,a[i].Rt);
    }
    printf("Average WT=%.3f\n",(float)total_Wt/n);
    printf("Average RT=%.3f\n",(float)total_Rt/n);
    printf("Average TAT=%.3f",(float)total_Tat/n);
    return 0;
}