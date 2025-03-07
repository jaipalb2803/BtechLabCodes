#include<stdio.h>
int main()
 	{
   		int i,j,k,m,n,p,q;
      	printf("entre no.of rows and column of Mat-1:");
		scanf("%d%d",&m,&n);
		printf("entre no.of rows and column of Mat-2:");
		scanf("%d%d",&p,&q);
		int a[m][n],b[p][q],c[m][n];
      	if(n==p)
		{
			printf("\nenter the %d in matrice-1:",m*n);
			for(i=0;i<m;i++)
			{
    			printf("\nenter  %d in row-%d:",n,i+1);
				for(j=0;j<n;j++)
				{
					scanf("%d",&a[i][j]);
				}
			}
			printf("\nenter the %d in matrice-2:",p*q);
			for(j=0;j<p;j++)
			{
    			printf("\nenter  %d in row-%d:",q,i+1);
				for(k=0;k<q;k++)
				{
					scanf("%d",&b[j][k]);
				}
			}
			printf("\nresult of Mat1xMat2 is:\n");
			for(i=0;i<m;i++)
			{ 
				printf("|");
				for(j=0;j<n;j++)
				{
					
					for(k=0;k<q;k++)
					{
						c[i][j]+=a[i][j]*b[j][k];
     				}
					printf(" %d\t",c[i][j]);
				}
				printf(" |\n");

   			}
      	}
		else
		{
			printf("operation is not valid");
		}
	}