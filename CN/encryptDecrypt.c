#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256

void encryptionData(char D[],int key)
{
    int i=0;
    while(i<strlen(D))
    { 
        D[i]=D[i]-key;
        i++;
    } 
    D[i]='\0';
    printf("Encrypted data=%s",D);

}
void decryptionData(char D[],int key)
{
    int i=0;
    while(i<strlen(D))
    {
        D[i]=D[i]+key;
        i++;
    } 
    D[i]='\0';
    printf("\nDecrypted data=%s",D);
}
int main()
{   
   int key;
   char D[N];
   printf("\nEnter the key=");
   scanf("%d",&key);
   getchar();

   printf("\nEnter the charecter data=");
   fgets(D,N,stdin);
   
   encryptionData(D,key);
   decryptionData(D,key);
    
}