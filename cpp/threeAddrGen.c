#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40

void push(char stk[],char ele,int *t)
{
		*t=*t+1;
		stk[*t]=ele;	
}
char pop(char stk[],int *t)
{
		char ch;
		ch=stk[*t];
		(*t)--;
		return ch;
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
void ThreeAddrCodeGenerator(char *str)
{
	  char *S1=(char*)calloc(N,sizeof(char)),S2[N],var1,var2,optr,c='0';
	  int top1=0,top2=0;

	  for(int i=0;i<strlen(str)-1;i++)
	  {
	  		if(str[i]>='a'&& str[i]<='z')
	 		 {
          //printf("%c",str[i]);
	  			push(S2,str[i],&top2);	  			
	 		 }
	 		 else if( inPrec(str[i])>stackPrec(S1[top1]) )
	 		 {
	 		 		push(S1,str[i],&top1);
	 		 }
	 		 else if( inPrec(str[i])<=stackPrec(S1[top1]))
	 		{
	 		  optr=pop(S1,&top1);
        var1=pop(S2,&top2);
        var2=pop(S2,&top2);
	 		 	c++;
        printf("t%c = %c %c %c\n",c,var1,optr,var2);
        //push(S2,c,&top2);
        while(top1)
	      {
            optr=pop(S1,&top1);
            var2=pop(S2,&top2);
	 		 	    c++;
            printf("t%c = %c %c t%c\n",c,var2,optr,c-1);
            push(S2,c,&top2);
	      }	
        push(S1,str[i],&top1);
	 		}   
	  }
	  while(top1)
	  {
            optr=pop(S1,&top1);
            var1=pop(S2,&top2);
            var2=pop(S2,&top2);
	 		 	    c++;
            (c=='1')? printf("t%c = %c %c %c\n",c,var2,optr,var1):  
            printf("t%c = t%c %c %c\n",c,c-1,optr,var1);    
    }
}
int main()
{
	 char Exp[N];
	
	 printf("Enter infix expression:");
	 fgets(Exp,N,stdin);
	 
	 ThreeAddrCodeGenerator(Exp);
}  
	 