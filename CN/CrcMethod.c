#include<stdio.h>
#include<stdlib.h>
void readInput(int a[],int n)
{
     for(int i=0;i<n;i++)
        scanf("%d",&a[i]);       
}
void sender(int f[],int g[],int c[],int n,int k)
{
    int s=(n-n/k)-1,i=0;

    for(int j=0;j<n && i<s;j++)
    {
         int p=j;
         if(f[j]==1)
         { 
             for(int w=0;w<k;w++)
             {
                f[p]=f[p]^g[w];
                p++;
             }         
          }
          else if(f[j]==0)
          {
              for(int w=0;w<k;w++)
              {
                  f[p]=f[p]^0;
                  p++;
              }
          }
          i++;            
     }
     for(int i=n-1,rev=k-2;rev>=0;rev--)
     {
            c[rev]=f[i];
            i--;
     }                
}
int receiver(int f[],int g[],int n,int k)
{
    int s=(n-n/k)-1,i=0;

    for(int j=0;j<n & i<s;j++)
    {
         int p=j;
         if(f[j]==1)
         { 
             for(int w=0;w<k;w++)
             {
                 f[p]=f[p]^g[w];
                 p++;
             }                   
          }
          else if(f[j]==0)
          {
              for(int w=0;w<k;w++)
              {
                  f[p]=f[p]^0;
                  p++;
              }
          }
          i++;            
     }
     int count=0;
     for(int i=n-1;i>n-k;i--)
     {
            if(f[i]==0)
              count++;
     } 
     if(count==k-1)
        return 1;
     else
        return 0;      
          
}
void AddCrcToDataBit(int data[],int crc[],int m,int n)
{
      int  j=m-2;
       for(int i=n-1;i>n-m;i--)
       {
            data[i]=data[i]|crc[j];
            j--;
       }     
}
void printOut(int a[], int n)
{
    for(int i=0;i<n;i++)
       printf("%d",a[i]);
    printf("\n");
}
int main()
{
  int s1,s2;
  printf("Enter the frame size=");
  scanf("%d",&s1);
  printf("\nEnter the generator size=");
  scanf("%d",&s2);
  
  int *f1=(int*)calloc(s1+s2,sizeof(int)),*f2=(int*)calloc(s1+s2,sizeof(int)),g[s2]; 
  printf("\nEnter the frame=");
  readInput(f1,s1);
  for(int i=0;i<s1;i++)
     f2[i]=f1[i];
  printf("\nEnter the generator=");
  readInput(g,s2);
  
  int crc[s2-1];
  sender(f2,g,crc,s1,s2);
  
  printf("\nYour crc remender:");
  printOut(crc,s2-1);
      
  int n=s1+s2-1,flag=0;
  printf("Before adding redundancy:");
  printOut(f1,n);
  AddCrcToDataBit(f1,crc,s2,n);
  printf("After adding redundancy:");
  printOut(f1,n);
  
  flag=receiver(f1,g,n,s2);
  (flag==1)?printf("\nRecevied CORRECT"):printf("\nReceived ERROR");
     
}
