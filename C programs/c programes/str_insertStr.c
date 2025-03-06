#include<stdio.h>
#include<string.h>
#define N 100
void insertStr(char s1[],char s2[],char s3[],int n,int p)
{
    int k=strlen(s2);
    for(int i=0,j=0;i<n+1;i++,j++)
    {
         if(i==p)
         {
            for(int s=0;s<k;s++)
            {
               s3[j]=s2[s];
               j++;
            }
            s3[j]=s1[i];

         }
         else
               s3[j]=s1[i];
    }
}
int main()
{
   char s1[N],s2[N],s3[N];
   int n,p;
   printf("enter 1st string:");
   scanf("%s",s1);
   printf("enter 2st string:");
   scanf("%s",s2);
   printf("enter the position:");
   scanf("%d",&p);
   n=strlen(s1)+strlen(s2)-2;
   insertStr(s1,s2,s3,n,p);
   printf("your string is %s",s3);
}