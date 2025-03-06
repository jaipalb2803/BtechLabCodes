#include <stdio.h>

    //c programe for binary to decimal
    int main()
    {
        int decimal=0,rem,weight=1,num;
            printf("enter the binary number:\n");
            scanf("%d",&num);
            while(num!=0)
            {
                rem=num%10;
                decimal=decimal+rem*weight;
                num=num/10;
                weight=weight*2;
            }
            printf("decimal equivalent of binary is %d",decimal);
    }
