#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    //c programe for find armstrong number
    int main()
    {
        int num,lastdigit,digit,sum,i,last;
        printf("enter the number:\n");
        scanf("%d",&last);

        printf("armstrong number between 1 to %d are:\n",last);
        for(i=1;i<=last;i++)
        {
            num=i;
            digit=log10(num)+1;
            sum=0;
            while(num>0)
            {
                lastdigit=num%10;
                sum=sum+(pow(lastdigit,digit));
                num=num/10;

            }
            if(i==sum)
            {
              printf("%d\n",i);
            }
        }
    }


