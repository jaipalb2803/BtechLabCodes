#include <stdio.h>
#include<stdlib.h>
#define N 256

typedef struct node{
   char msg[N];
   int seq;
}Frame;

void readFrameSeq(Frame B[],int n)
{
   for(int i=0;i<n;i++)
   {
      printf("Enter the message-%d=",i+1);
      scanf("%s",&B[i].msg);
      B[i].seq=rand()%n; 
   }
}
void printFrameSeq(Frame B[],int n)
{
   for(int i=0;i<n;i++)
      printf("%d\t%s\n",B[i].seq,B[i].msg);
    printf("\n");      
}
void sortFrames(Frame B[],int n)
{
    for(int i=0;i<n-1;i++)
      for(int j=0;j<n-i-1;j++)
         if(B[j].seq>B[j+1].seq)
         {
            Frame swap=B[j];
            B[j]=B[j+1];
            B[j+1]=swap;
         }
}
int main()
{
    int n;
    printf("Enter total no of frame=");
    scanf("%d",&n);
    Frame Buffer[n];
    readFrameSeq(Buffer,n);
    sortFrames(Buffer,n);
    printf("Sorted frames:\n");
    printFrameSeq(Buffer,n);   
}