#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40

void push(char stk[],char c,int *t)
{
		*t=*t+1;
		stk[*t]=c;	
}
int inPrec(char ch)
{
		switch(ch)
		{
		    case 0 : return 0;
		             break;	
			case '+': return 1;
					break;
			case '-': return 1;
					break;
			case '*': return 3;
					break;
		     case '/': return 3;
					break;
			case 	'^'	: return 6;
					break;

		}
}
int stackPrec(char ch)
{
		switch(ch)
		{
		    case 0: return 0;
					break;		
			case '+'  : return 2;
					break;
			case  '-'  : return 2;
					break;
			case '/' : return 4;
					break;
			case '*': return 4;
					break;
			case  '^'	: return 5;
					break;
			default:return 0;            
		}
}
char pop(char stk[],int *t)
{
		char ch;
		ch=stk[*t];
		(*t)--;
		return ch;
}
void postfixConvrt(char *s,char a[])
{
	  char *stk;
	  stk=(char*)calloc(N,sizeof(char));
	  int j=0,top=0,n;
	  n=strlen(s)-2;

	  for(int i=0;i<=n;i++)
	  {
	  		if(s[i]>='a'&& s[i]<='z')
	 		 {
	  			a[j]=s[i];
	  			j++;
	 		 }
	 		 else if( inPrec(s[i])>stackPrec(stk[top]) )
	 		 {
	 		 		push(stk,s[i],&top);
	 		 }
	 		 else if( inPrec(s[i])<=stackPrec(stk[top]))
	 		{
	 		 	a[j]=pop(stk,&top);
	 		 	j++;
	 		 	if(inPrec(s[i])>stackPrec(stk[top]))
	 		 	{
	 		 	     push(stk,s[i],&top);	
	 		 	}
	 		 	else if( inPrec(s[i])<=stackPrec(stk[top]))
				{
					a[j]=pop(stk,&top);
	 		 		j++;
					if(inPrec(s[i])>stackPrec(stk[top]))
					 push(stk,s[i],&top);
				}
	 		}
	  }
	  while(top)
	  {
		 a[j]=pop(stk,&top);
	 	 j++;
	  }
	  
}
int main()
{
	 char *s,*a,ch;
	 s=(char*)calloc(N,sizeof(char));
	 a=(char*)calloc(N,sizeof(char));

	 printf("Enter infix expression:");
	 fgets(s,N,stdin);
	 
	 postfixConvrt(s,a);
	 printf("postfix expression :%s\n",a);
}