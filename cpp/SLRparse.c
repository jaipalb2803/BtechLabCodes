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
int getNonTerminal(Prd P[],int n,int c,char R[]){
   
    for(int i=0;i<n;i++){
      if(i==0){     
          R[c]=P[i].v;
          c++;
       }
       else if(P[i].v!=P[i-1].v){
         R[c]=P[i].v;
         c++;
       }      
    }
    return c;
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
void ParseTable(char col[],int r,int c,Prd PT[r][c]){
    
	  int a[r][c],n,j1;
	  
      for(int i=0;i<r;i++){
	     j1=0;
         printf("Enter no of Prod Item-%d=",i);
	     scanf("%d",&n);
	     printf("Enter item ProdNumber=");
         for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
	     getchar();	
	     printf("Enter item Production=");
	     for(int j=0;j<n;j++)
            scanf("%s",PT[i][a[i][j]].w);	
         for(int j=0;j<=c;j++)
            if(j!=a[i][j1])
	          PT[i][j].w[N]="X\0",j1++;		
	     printf("\n");				
      }  

      for(int i=0;i<=c;i++)
         printf("\t%c",col[i]);
      printf("\n");
      for(int i=0;i<r;i++)
      {
	     for(int j=0;j<c;j++)
		   (j==0)?printf("\nI%d\t%s",i,PT[i][j].w):printf("\t%s",PT[i][j].w);
			 
      }	   
}
int main(){
    int n,r,c;
    printf("Enter no.of production=");
    scanf("%d",&n);

    Prd P[n],parTbl[N][N];
    readProd(P,n);   
    printf("Enter no.of Items=");
    scanf("%d",&r);
    char* col=(char*)calloc(N,sizeof(char));
     
    c=GetTerminal(P,n,col);
    c=getNonTerminal(P,n,c+1,col);
    
    ParseTable(col,r,c,parTbl);
   
}

