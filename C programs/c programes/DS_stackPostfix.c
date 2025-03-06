#include<stdio.h>
#include<string.h>
#include <math.h>
#include<stdlib.h>
#define N 40

typedef struct node
{
  float data;
  struct node *link;
}node;

void push(node**first,float ele)
{
	node*new=(node*)malloc(sizeof(node));
	new->data=ele;
	if(first==NULL)
	{
		new->link=NULL;
		*first=new;
	}
	else
	{
		new->link=*first;
		*first=new;
	}
}
float pop(node**first)
{
	node*temp;
	float a;
	temp=*first;
    a=(*first)->data;
	*first=(*first)->link;
	free(temp);
	return a;

}
void printResult(node*first)
{
	printf("Result=");
    if(first==NULL)
       printf("0");
	else
	{
		while(first)
       {
        printf("%5f",first->data);
        first=first->link;
       }
	}
}
int main()
{
	float a,b;
	char s[N];
	node *first=NULL;
	printf("Enter the postfix expression?:");
	fgets(s,30,stdin);
	
	for(int i=0;i<(strlen(s)-1);i++)
	{
         if(s[i]>='a'&&s[i]<='z')
		 {
			printf("enter value of %c:",s[i]);
	 		scanf("%f",&a);
	  		push(&first,a);
		
		 }
		 else
		 {
			switch (s[i])
			{
			case'+':b=pop(&first);
			        a=pop(&first);
					push(&first,a+b);
				break;
			case'-':b=pop(&first);
			        a=pop(&first);
					push(&first,a-b);
				break;
			case'/':b=pop(&first);
			        a=pop(&first);
					push(&first,a/b);
				break;
			case'*':b=pop(&first);
			        a=pop(&first);
					push(&first,a*b);
				break;
			case'^':b=pop(&first);
			        a=pop(&first);
					push(&first,pow(a,b));
				break;
			default:printf("enter the correct reprasentation");
				break;
			}
		 }
	}
    printResult(first);

}