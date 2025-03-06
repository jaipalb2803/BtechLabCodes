#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
    int m,k,n,i,a[10];
    FILE *fp;
    fp=fopen(argv[1],"wb");
    if(argc!=12)
     {
        puts("error! use correct format ./a.exe 1 2...n");
    }
    else
    {
        for(i=0;i<10;i++)
        {
            a[i]=atoi(argv[i+2]);
            fprintf(fp,"%d\t",a[i]);   
        }
        puts("enter your index:");
        scanf("%d",&n);
        printf("enter the value:");
        scanf("%d",&m);
        a[n-1]=m;
        fseek(fp,0,SEEK_SET);
        for(i=0;i<10;i++)
        { 
            fprintf(fp,"%d\t",a[i]);
        }
    } 
    fclose(fp);
}