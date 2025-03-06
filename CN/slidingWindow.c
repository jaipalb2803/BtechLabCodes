#include <stdio.h>
#include <stdlib.h>

int f=0,r=0;
void frameSeq(int F[],int m)
{
   for(int i=0;i<m;i++)
        F[i]=i;  
}
void enqueue(int F[],int s[],int n)
{
    if(f==r)
    {
        for(int i=0;i<n;i++)
        {    
            s[i]=F[i];
            f++;
        }   
    }
    else
    {
        for(int i=0;i<n-1;i++)
           s[i]=s[i+1];
        s[n-1]=F[f];
        f++;
    }   
}
void dequeue(int R[],int s[],int m,int *i)
{
      if(f==r){
         printf("frame is Empty.");
      }
      else if(f<m)
      {
         R[r]=s[*i];
         r++;
      }
      else
      {  
         R[r]=s[*i];
         r++;
         (*i)++;
      }       
}
void receiveSeq(int R[],int m)
{
   for(int i=0;i<m;i++)
      printf("%d\t",R[i]);
    printf("\n");      
}
int main()
{
    int n,m;
    printf("enter total no of frame=");
    scanf("%d",&m);
    printf("enter the window size=");
    scanf("%d",&n);
    int F[m],s[n],R[m];
    frameSeq(F,m);
    int i=0;
    printf("sliding window:\n");
    while(r<m)
    { 
        if(f<m)
           enqueue(F,s,n);  //sender slide
        receiveSeq(s,n);
        dequeue(R,s,m,&i);  //receiver slide
    }
    (f==r)?printf("Data received\n"):printf("Data Interrupted\n");
    if(f==r)receiveSeq(R,m);  
}