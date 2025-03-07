#include<stdio.h>
#include<stdlib.h>

int checkHashTbl(int h[],int m)
{
     int c=0;
     for(int i=0;i<m;i++)
     {
         if(h[i]!=0)
            c++;
     }
     if(c==m)
        return 1;
     else
        return 0;
            
        
}       
void linearProbeInsert(int h[],int k,int m)
{
        int probe;
        if(checkHashTbl(h,m))
        {
            printf("ERROR !..Hash Table is full\n");
        }
        else
        {
            probe=k%m;
            while(h[probe]!=0)
            {
                probe=(probe+1)%m;
            }
            h[probe]=k;
            
        }
}
void hashTable(int h[],int i,int m)
{
    
    int key;
    printf("Enter the element-%d=",i+1);
    scanf("%d",&key);

    linearProbeInsert(h,key,m);
     

}
void printHashTable(int h[],int m)
{
     for(int i=0;i<m;i++)
    {
         if(h[i]!=0)
           printf("%d\t",h[i]);
         else
           printf("X\t");
          
    }
}
int main()
{
    int m,n;
    printf("Enter the size of hash Table=");
    scanf("%d",&m);

    int *h=(int*)calloc(n,sizeof(int));

    printf("Enter the no of element=");
    scanf("%d",&n);
     
    printf("DATA ENTRY:\n");
    for(int i=0;i<n;i++)
        hashTable(h,i,m);
    
    printf("HASH TABLE IS :");
    printHashTable(h,m);

    free(h);

}