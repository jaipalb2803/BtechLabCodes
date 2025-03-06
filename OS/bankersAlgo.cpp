 
 #include<stdio.h>
 #include <stdlib.h>

int main()
 {
 		int p,r;
  		printf("Enter No of Process:");
  		scanf("%d",&p);
  		printf("Enter No of resources:");
  		scanf("%d",&r);
  		int alloc[p][r],avail[r],need[p][r],max[p][r],maxRes[r];
		int *sum=(int*)calloc(r,sizeof(int));

  		printf("Enter total resources:");
  		for(int i=0;i<r;i++)
             scanf("%d",&maxRes[i]);  

  		printf("Enter matrix of Allocation:\n");
  		for(int i=0;i<p;i++)
 		  for(int j=0;j<r;j++)
              scanf("%d",&alloc[i][j]);

  		printf("Enter matrix of Max:\n");
  		for(int i=0;i<p;i++)
 		  for(int j=0;j<r;j++)
              scanf("%d",&max[i][j]); 

  		for(int i=0;i<p;i++)
 		 for(int j=0;j<r;j++){
			sum[j]+=alloc[i][j];
            need[i][j]=max[i][j]-alloc[i][j];
		 }

		 for(int i=0;i<r;i++)
			avail[i]=maxRes[i]-sum[i];
        printf("\nAllocated resources: ");
    	for (int i = 0; i < r; i++)
        	printf("%d ", sum[i]);
		
		printf("\nAvailable resources: ");
    	for (int i = 0; i < r; i++)
       		 printf("%d ", avail[i]);
   	    printf("\n");

  		int *run=(int*)calloc(p,sizeof(int)),count=p,c,check=0;
		printf("PROCESSES :\n");
		while(count>0)
		{
		       c=0;
		       for(int i=0;i<p;i++)
		       {
		       		if(run[i]==0)
		       		    for(int j=0;j<r;j++) {
		       		      	if(need[i][j]<=avail[j])
		       		      		check++;	 
		       		      	else
		       		      		break;
		       		   }     
		       		if(check==r){
		       			 for(int j=0;j<r;j++){
		       			       avail[j]+=alloc[i][j];
		       			 }
		       			 count--;
						 run[i]=1;
		       			 printf("P%d\t",i);
					}
					else
						c++;
					check=0;
		       }
		    if(c==p){
		       printf("Processes are in  Unsafe state\n");
		       break;
		     }
		    else if(count==0)
		        printf("\nProcesses Executed..!");
		       
		}  			 		
 }
