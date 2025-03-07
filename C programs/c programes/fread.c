#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    FILE *p;
    int i,num,pos;

    if(argc!=12)
    {
        printf("eroor in file name ");
    }
    else 
    {
        p=fopen(argv[1],"wb+");
        if(p==NULL)
        {
            printf("file open problem %s ",argv[1]);
        
        }
        else
        {
            for(i=2;i<12;i++)
            {
                num=atoi(argv[i]);
                fwrite(&num,1,sizeof(int),p);
                
            }
            //system("cls");
            for(i=0;i<10;i++)
            {
                //fseek(p,i*sizeof(int),SEEK_SET);
                fread(&num,i,sizeof(int),p);
                printf("%d",num); 

            }
            printf("\n");
            printf("Enter the new number : ");
            scanf("%d",&num);
            printf("Enter the position(1-10);_");
            scanf("%d",&pos);
            printf("\n");
            fseek(p,(pos-1)*sizeof(int),SEEK_SET);

        }
    }
}