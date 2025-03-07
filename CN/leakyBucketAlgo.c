#include <stdio.h>
#include <stdlib.h>

int f=0,r=0;

void enqueFullBucket(int B[],int n)
{
   for(int i=0;i<n;i++)
   {
      if(r>n)
        printf("BUCKET OVERFLOW"); 
      else
      {      
        printf("Enter the Data-%d=",i+1);
        scanf("%d",&B[r]);
        r++;   
      }  
   }
}
int dequeue(int B[])
{
    int data;
    if(f>=r)
        printf("BUCKET UNDERFLOW");
    else
    {
        data=B[f];
        f++; 
        return data;  
    }       
}
int checkValidDataSize(int B[],int n,int s)
{
    int count=0;
    for(int i=0;i<n;i++)
      if(s>=B[i])
        count++;
    return count;
}
int main() 
{
    int n,s;
    printf("enter the Bucket size=");
    scanf("%d",&n);
    printf("enter the data rate size=");
    scanf("%d",&s);
    int B[n];
    enqueFullBucket(B,n); 
    int i=1,dataRt=s,packet,flag=1;
    
    if(n==checkValidDataSize(B,n,s))
    {
        if(flag)
        {
            printf("\nTime\t Packets\tstatus\n");
            flag=0;
        }    
        while(f<r)
        { 
          if(s>=B[f])
          {
            s=s-B[f];
            packet=dequeue(B); 
            printf("%ds\t  %dMbps\tAccepted\n",i,packet);
          }
          else
          {
            i++;
            s=dataRt;
          }
        }
    }
    else
    {
        printf("ERROR OF DATA SIZE");
    }
    (f==r)?printf("Data received\n"):printf("\n3Data Interrupted\n");
      
}