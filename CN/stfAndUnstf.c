#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256
char f[]="flag";
char e[]="esc";

char* bitStuffing(char data[],char *sd,int *n){
    int count=0,j=0,i=0,s=*n;
    while(i<s)
    {
        if(data[i]=='1')
            count++;
        else
          count=0;
        sd[j]=data[i];
        j++,i++;
        if(count==5)
        {
            count=0;
            n++;
            sd[j]='0';
            j++;
        }
    }
    sd[j]='\0';
    printf("stuffed data=%s",sd);
    return sd;
}
void bitUnstuffing(char sd[],char ud[],int n){
    int count=0,j=0,i=0;
    while(i<=n+1)
    {
        if(sd[i]=='1')
            count++;
        else
          count=0;
        ud[j]=sd[i];
        j++,i++;
        if(count==5)
        {
            count=0;
            i++;        
        }
    }
    ud[j]='\0';
    printf("\nUnstuffed data=%s",ud);
}
void charStuffing(char d[],char s[])
{
    int i=0,j=0;
    while(i<strlen(d))
    {
         int c=0;
         if(d[i]=='f')
         {
             int k=i;
             for(int i2=0;i2<strlen(f);i2++)
                if(d[k]==f[i2])
                    k++,c++;
                else
                    break;
             if(c==strlen(f))
                for(int i2=0;i2<strlen(e);i2++)
                    s[j]=e[i2],j++;    
         }
         else if(d[i]=='e')
         {
             int k=i;
             for(int i2=0;i2<strlen(e);i2++)
                if(d[k]==e[i2])
                    k++,c++;
                else
                     break;
             if(c==strlen(e))
                for(int i2=0;i2<strlen(e);i2++)
                    s[j]=e[i2],j++;    
         }
         s[j]=d[i],i++,j++;
    } 
    s[j]='\0';
     printf("stuffed data=%s",s);

}
void charUnstuffing(char s[],char u[])
{
    int i=0,j=0;
    while(i<strlen(s))
    {
         int c=0;
         if(s[i]=='e')
         {
             int k=i;
             for(int i2=0;i2<strlen(e);i2++)
             {
                  if(s[k]==e[i2])
                       k++,c++;
                  else
                     break;
             }
             if(c==strlen(e))
                i+=strlen(e);
                      
         }
         u[j]=s[i],i++,j++;
    } 
    u[j]='\0';
     printf("unstuffed data=%s",u);

}
int main(){
    int n;
    printf("Enter the size of data=");
    scanf("%d",&n);
    char data[n];
    
    printf("Enter the binary data=");
    scanf("%s",data);
    char *sd=(char*)calloc((n+n/5),sizeof(char)),ud[n];
    bitStuffing(data,sd,&n);
    bitUnstuffing(sd,ud,n);
    getchar();

   char d[N],s[N],u[N];
   printf("\nEnter the charecter data=");
   fgets(d,N,stdin);
   
   charStuffing(d,s);
   charUnstuffing(s,u);
    
}