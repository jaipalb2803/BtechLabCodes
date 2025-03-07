#include <stdio.h>
struct pt
{
    int x1;int x2;int x;
    int y1;int y2;int y;
}p;  
int main()
{
  int k;
  printf("enter the values of point P =");
  scanf("%d%d",&p.x1,&p.y1);
  printf("enter the values of point Q =");
  scanf("%d%d",&p.x2,&p.y2);
  p.x=p.x2-p.x1;
  p.y=p.y2-p.y1;k=p.x*p.y;
  (k>0)?
  printf("Area of the rectangle is =%d sq units",k):
  printf("rectangle is not for with your points");

}