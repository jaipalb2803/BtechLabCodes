// C program to demonstrate use of ftell,rewind							
#include<stdio.h>
#include<stdlib.h>

void printFile(FILE *fp)
{ 
   char c;
   while(1)
   { 
      c=getc(fp);
      if(c!=EOF)
		   printf("%c",c);
      else
         break;
	}
}
int main()
{
   FILE *fp;
   char c;
   system("cls");
   fp = fopen("sample.txt","r");
   printFile(fp);
   printf("-%d\n",ftell(fp));
   rewind(fp);
   printFile(fp);
	fclose(fp);
}
