#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    //c programe for find guess of computer
    srand(time(0));
    int num =rand()%10,count=1;
    printf("enter the number between 0 and 9\n");
    int guess;
    printf("enter the number: ");
    scanf("%d",&guess);
    while(guess!=num)
    {
        if(guess>num)
        {
            printf("enter the lower number:\n");
            printf("enter the number: ");
            scanf("%d",&guess);
        }
        else if(guess<num)
        {
            printf("enter the higher number:\n");
            printf("enter the number: ");
            scanf("%d",&guess);
        }
        count++;
    }
    if(guess==num)
    {
        printf("BINGO!!you have done it in %d attempts\n",count);
    }
    return 0;
}
