#include <stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	printf("enter no of names:");
	scanf("%d",&n);
	char s[n][20],t[20];
	printf("enter any %d names:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(strcmp(s[j-1],s[j])>0)
			{
				strcpy(t,s[j-1]);
				strcpy(s[j-1],s[j]);
				strcpy(s[j],t);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%s",s[i]);
	}

}