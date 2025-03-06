#include<stdio.h>
#include<string.h>

char prol[3][10]={"S","A","A"};
char pror[3][10]={"Aa","b","@"};
char prod[3][10]={"A->Aa","A->b","A->@"};
char first[3][10]={"ab","b","@"};
char follow[3][10]={"$","a","a"};
char table[3][4][10];

int num(char c){
	 switch(c){
		case 'S':return 0;
		case 'A':return 1;
		case 'a':return 0;
		case 'b':return 1;
		case '$':return 2;
	 }
	 return 2;
}
int main(){
	int i,j;
	printf("Predictive parsing:");
	printf("\n----------------------------------------------\n");
	for(i=0;i<3;i++){
		for(j=0;j<strlen(first[i]);j++){
			if(first[i][j]!='@')
			   strcpy(table[num(prol[i][0])+1][num(first[i][j])+1],prod[i]);
			else{
				for(int p=0;p<strlen(follow[i]);p++){
					strcpy(table[num(prol[i][0])+1][num(follow[i][p])+1],prod[i]);
				}		
			}
			  
		}
	}
	strcpy(table[0][0]," ");
	strcpy(table[0][1],"a");
	strcpy(table[0][2],"b");
	strcpy(table[0][3],"$");
	strcpy(table[1][0],"S");
	strcpy(table[2][0],"A");

	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
		{
			printf("%-10s",table[i][j]);
			if(j==3)
			 printf("\n----------------------------------------------\n");
		}
		
	}
}