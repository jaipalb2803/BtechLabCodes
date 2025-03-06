#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 64

typedef struct Prd{
    char v,w[N];
}Prd;

void readProd(Prd P[],int n)
{
    int r=0,j;
    while(n!=0){
        char s[N];
        printf("Enter %d production:",r+1);
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
          if(s[i]!='-'&s[i]!='>'){
            if(i==0)
               P[r].v=s[i],j=0;
            else
               P[r].w[j]=s[i],j++;
          }
        }
        P[r].w[j]='\0';
        //printf("\n%c->%s\n",P[r].v,P[r].w);
        n--,r++;
    }
}
int readFirstFollow(Prd P[],int n,Prd F[],Prd f[],char R[]){
    int count=0; 
    for(int i=0;i<n;i++){
      if(i==0){
          printf("First(%c)=",P[i].v);
          scanf("%s",F[count].w);
          printf("Follow(%c)=",P[i].v);
          scanf("%s",f[count].w);
          R[count]=P[i].v;
          count++;
      }
      else if(P[i].v!=P[i-1].v){
        printf("\nFirst(%c)=",P[i].v);
        scanf("%s",F[count].w);
        printf("Follow(%c)=",P[i].v);
        scanf("%s",f[count].w);
        R[count]=P[i].v;
        count++;
      }      
    }
    return count;
}
int IsAbs(char S[],char c){
   int flag=1;
   for(int i=0;i<strlen(S);i++)
       if(S[i]==c){
          flag=0;
          break;
       }
     return flag;  
}
int GetTerminal(Prd P[],int n,char col[]){
   int i,c=0;
     for(i=0;i<n;i++){
        for(int j=0;j<strlen(P[i].w);j++)
        {
          if(!(P[i].w[j]>='A' && P[i].w[j]<='Z') & IsAbs(col,P[i].w[j]) & P[i].w[j]!='#' )
              col[c]=P[i].w[j],c++;       
        }
     } 
   col[c]='$';   
   return c;
}
void ParseTable(Prd F[],Prd f[],Prd P[],char col[],char row[],int r,int c){
      for(int i=0;i<=c;i++)
         printf("\t%c\t",col[i]);
       printf("\n"); 
      for(int i=0,j=0;i<r;i++){
         printf("%c ",row[i]);
         for(int j1=0;j1<strlen(F[i].w);j1++)
         {
            if(F[i].w[j1]!=','&F[i].w[j1]!='#'&P[j].v==row[i]){
                printf("\t%c->%s\t",P[j].v,P[j].w);
                j++;
            }
            else if(F[i].w[j1]=='#'){
                 for(int j2=0;j2<strlen(f[i].w);j2++){
                    if(f[i].w[j2]!=','&P[j].v==row[i]){
                        printf("\t%c->%s\t",P[j].v,P[j].w);
                    }
                 }
                 j++;break;
            }
         }
        printf("\n");       
      }    
}
int main(){
    int n,r,c;
    printf("Enter no.of production=");
    scanf("%d",&n);

    Prd P[n],first[n],follow[n];
    readProd(P,n);   
    char row[n];
    char *col=(char*)calloc(n,sizeof(char));
    
    r=readFirstFollow(P,n,first,follow,row);
    c=GetTerminal(P,n,col);
    
    ParseTable(first,follow,P,col,row,r,c);
     /*for(int i=0;i<=c;i++)
      printf("\t%c",col[i]);
    for(int i=0;i<r;i++)
      printf("\n%c",row[i]);
     printf("\n%d\t",c);
    for(int i=0;i<c;i++)
      printf("%s\t%s\n",first[i].w,follow[i].w);*/
   
}
