#include<stdio.h>
#include<string.h>
#define N 50

int stringMatch(char T[],char P[])
{
     
     int i,j,m,n;
     n=strlen(T)-2;
     m=strlen(P)-2;
     for(i=0;i<n-m;i++)
     {
        j=0;
        while(j<m && P[j]==T[i+j])
        {
            j=j+1;
        }
        if(j==m)
          return i;
     }
     return -1;
}
int main()
{
     char T[N],P[N],k;
    printf("Enter  the TEXT  to compare:");
    fgets(T,N,stdin);

    printf("Enter the PATTERN to compare:");
    fgets(P,N,stdin);

    k=stringMatch(T,P);
    
    (k!=-1)?printf("PATTERN is found at position : %d ",k+1):
    printf(" PATTERN is not found in TEXT");
     
    

}