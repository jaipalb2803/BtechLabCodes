#include <stdio.h>
#include <stdlib.h>

    //c programe for palindroms
    int main()
    {
        int num,sum=0,c,rem;
        printf("enter the number:\n");
        scanf("%d",&num);
        c=num;
        while(num!=0)
        {
          rem=num%10;
          sum=sum*10+rem;
          num=num/10;

        }
       (c==sum)?
        printf("palindrom"):
        printf("not palindrom");
    }
