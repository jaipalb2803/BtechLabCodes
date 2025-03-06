#include<stdio.h>
#define SIZE 50
void insertionAtEnd(int a[],int n)
{
    printf("Enter element to insert at end=");
    scanf("%d",&a[n]);
}
void insertionAtBeginning(int a[],int n)
{
    int ele;
    printf("Enter the element to insert at beginning=");
    scanf("%d",&ele);
    while(n>=0)
    {
        a[n]=a[n-1];
        n--;
    }
    a[0]=ele;
}
void insertionAtPosition(int a[],int n)
{
    int ele,pos;
    printf("Enter the element to insert=");
    scanf("%d",&ele);
    printf("Enter the position to insert=");
    scanf("%d",&pos);
    if(pos>n+1||pos<0)
        printf("Entered position is more than no.of elements.\n");
    else
    {
        while(n!=pos-1)
        {
            a[n]=a[n-1];
            n--;
        }
        a[pos-1]=ele;
    }
}
void display(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
}
int main()
{
    int a[SIZE],n,i;
    
    printf("Enter the number of elements=");
    scanf("%d",&n);
    
    i=0;
    while(i<n)
    {
        printf("Enter the %d element=",i+1);
        scanf("%d",&a[i]);
        i++;
    }
    do
    {
        printf("Enter the choice to perform.\n1.insertion at beginning\t2.insertion at end\t3.insertion at given position\t4.display\nEnter your choice=");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                insertionAtBeginning(a,n);
                n++;
                break;
            case 2:
                insertionAtEnd(a,n);
                n++;
                break;
            case 3:
                insertionAtPosition(a,n);
                n++;
                break;
            case 4:
                display(a,n);
                break;
            default :
                printf("Enter correct choice.");
                   
        }
    }while(i!=4);
    return 0;
}