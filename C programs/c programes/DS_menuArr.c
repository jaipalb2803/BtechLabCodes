#include<stdio.h>
#include<stdlib.h>
#define N 30

void readArray(int a[],int n)
{
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
 	}
}
 int insertElement(int a[],int n)
 {
 	int k,p,i,temp1,temp2;
 	printf("Enter position of element:");
 	scanf("%d",&p);
 	printf("Enter the element value:");
 	scanf("%d",&k);
 	if(p>0&p<n||p==n)
 	{
 		for(i=0;i<n;i++)
 		{
 			if(i==p-1)
 			{
 				temp1=a[i];
 				a[i]=k;
 			}
 			else if(i>p-1)
 			{
 			      temp2=a[i];
 			      a[i]=temp1;
 			      temp1=temp2;
 			}	
 		}
 	}
	else
	{
		printf("Enter valid position");
	}
 	return(n);
 }
 int printArray(int a[],int n)
 {
 	printf("After insertion result is:");
 	for(int i=0;i<n;i++)
 	{
 		printf("%3d",a[i]);
 	}
 }
 int  deleteElement(int a[],int n)
 {
     int k;
     printf("Enter the delete ele:");
     scanf("%d",&k);
     for(int i=0;i<n;i++)
     {
     		if(i>=k-1)
     		{
     		    a[i]=a[i+1];
     		}
     }
     return n-1;
 }
 void Search(int a[],int n)
 {
       int i,k,flag=0;
       printf("Enter your key ele:");
       scanf("%d",&k);
       for( i=0;i<n;i++)
       {
       			if(k==a[i])
       			{ 
       			 	flag=1;
       			 	break;
       			}
       }
       (flag==1)?printf("key-%d found at position-%d",k,i+1):printf("key is not found in array");
 }
 int main()
 {
 	int n,a[N],ch,k,size;
 	printf("Enter the size of the  array:");
 	scanf("%d",&n);
 	readArray(a,n);
        while(1)
        {
 		printf("\nChoice the following:\n1.insertion \n2.deletion\n3.searching\n4.exit\nEnter your choice:");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:n=insertElement(a,n+=1);
 			            printArray(a,n);
 						break;
 			case 2: n=deleteElement(a,n);
 			 	       printArray(a,n);
 						break;
 			case 3:Search(a,n);
 				       break;
 		        case 4:exit(0);
 		                  break;
 		         default: printf("Please enter correct option..!!");
 				  	        
 		}
 	}
 	
 	
 }