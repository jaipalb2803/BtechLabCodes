
#include<stdio.h>

struct emp
{
    char name[10];
    int age;
};
int main()
{
    FILE *p,*q;
    struct emp e[5];
    p = fopen("sample.txt", "a");
    for(int i=0;i<5;i++)
    {
        printf("Enter Name and Age candidate-%d:",i+1);
        scanf("%s %d", e[i].name, &e[i].age);
        fprintf(p,"%s %d\n", e[i].name, e[i].age);
    }
    fclose(p);
    q=fopen("sample.txt", "r");
    char c;
    while (1)
    {
        c=fgetc(q);
        if(c==EOF)
          break;
        else
          printf("%c",c);
          
    }
    fclose(q);
} 