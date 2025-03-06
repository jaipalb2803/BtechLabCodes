#include <stdio.h>
#include <string.h>

 typedef struct Student
{
 char name[50];
 int class;
 char section;
}STU; 
void addr(STU *p);

int main()
{

  STU s;
 
  // accessing student1 member and initialzing them
  printf("enter student name:");
  fgets(s.name,50,stdin);
  printf("enter student class and section:\n");
  scanf("%d %c",&s.class,&s.section);
  addr(&s);
}
void addr(STU *p)
{
 
 // printing address
 printf( "\nStudent Name : %s", p->name);
 printf( "Student Class : %d\n", p->class);
 printf( "Student Section : %c", p->section);

}
