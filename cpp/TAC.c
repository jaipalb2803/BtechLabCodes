#include<stdio.h>
#include<string.h>
int getPriority(char x){
	switch(x){
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
	}
	return -1;
}
void TAC(char *exp){
	char var='Z';
	for(int i=0;i<strlen(exp);i++){
		if(i>0 && getPriority(exp[i])==2){
			printf("%c=%c %c %c\n",var,exp[i-1],exp[i],exp[i+1]);
			exp[i-1]=var;
			for(int j=i;j<strlen(exp)-1;j++){
				exp[j]=exp[j+2];
			}
			var--;
			i=0;
		}
	}
	for(int i=0;i<strlen(exp);i++){
		if(i>0 && getPriority(exp[i])==1){
			printf("%c=%c %c %c\n",var,exp[i-1],exp[i],exp[i+1]);
			exp[i-1]=var;
			for(int j=i;j<strlen(exp)-1;j++){
				exp[j]=exp[j+2];
			}
			var--;
			i=0;
		}
	}
}
int main(){
	char exp[100];
	printf("Enter the expression: ");
	scanf("%s",exp);
	int len=strlen(exp);
	TAC(exp);
}