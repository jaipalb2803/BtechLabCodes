#include<stdio.h>
void minmax(int a[],int len,int *min,int*max)
{
   *min=*max=a[0];
   int i;
   for(i=1;i<len;i++)
   {
      if(a[i]>*max)
       *max=a[i];
      if(a[i]<*min)
       *min=a[i];
   }
}
int main()
{
   int a[]={23,5,24,78,456,0,31,79,38,389,8,96,12,3};
   int min,max;
   int len=sizeof(a)/sizeof(a[0]);
   minmax(a,len,&min,&max);
   printf("min value is %d and max value %d amonge %d integers",min,max,len);
}