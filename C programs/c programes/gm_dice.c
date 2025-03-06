#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    //A game rolling of two die you and computer by c program
    int myD1,myD2,yrD1,yrD2,n,c,r1,r2,s;s=1;
    while (s!=2)
    {
    srand((unsigned)time(0));
    printf("Let's play a game.\n");
    printf("The highest score,sum of two dice will win a round\n");
    printf("1.start\n2.Quit");
    printf("\nenter the your choice:");
    scanf("%2d",&n);
    if(n==1)
    {
        myD1=rand()%6+1; myD2=rand()%6+1; 
        printf("my dice outcome %2d%2d\n",myD1,myD2);
        printf("Now it is your turn to go\n");
        printf("1.Roll\n2.Skip");
        printf("\nenter the your choice:");
        scanf("%2d",&c);
        if(c==1)
        {
            yrD1=rand()%6+1; yrD2=rand()%6+1;
            printf("your dice outcome %2d%2d\n",yrD1,yrD2);
            r1=myD1+myD2;r2=yrD1+yrD2;
            if(r1>r2)
            {
                 printf("YOU LOST THE GAME !");
            }
            else if(r2>r1)
            {              
                printf("YOU WON THE GAME !");
            }  
            else
            {
                 printf("GAME IS TIE !");

            }
            printf("\n");
            printf("\n1.Replay\n2.Quit");
            printf("\nenter the your choice:");
            scanf("%2d",&s);
        }
         else 
        {
            printf("THE GAME IS END");
            goto end;
        }
    }
    else 
    {
        printf("THE GAME IS END");
        goto end;
    }
  }
   end: printf("__**GAME OVER**__");
}
