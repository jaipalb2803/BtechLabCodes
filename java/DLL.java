import java.util.Scanner;

class node
{
    int data;
    node pre,nxt;
    node(int a)
    {
        data=a;
    }
}
class operation
{
    node createDLL(node head)
    {
        int n;
        System.out.print("Enter no of nodes=");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        node temp=head;
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter nodes "+(i+1)+"data=");
            node New=new node(sc.nextInt());
            New.pre=New.nxt=null;
            if(i==0)//head==null
            {
                head=temp=New;
            }
            else
            {
                New.pre=temp;
                temp.nxt=New;

            }
            temp=New;
        }
        return head;
    }
    node deleteNode(node head)
    {
        System.out.print("Enter nodes data to delete=");
        Scanner sc=new Scanner(System.in);
        int del=sc.nextInt();
        node temp=head;
        while(temp!=null)
        {
            if(del==temp.data)
               break;
            temp=temp.nxt;
        }
        if(temp==head && head!=null)
            head=temp.nxt;
        else if(temp==null)
             System.out.print("Entered nodes data not found");
        else
            if(temp.nxt==null)
               temp.pre.nxt=null;
            else{
                temp.pre.nxt=temp.nxt;
                temp.nxt.pre=temp.pre;
            }
        sc.close();
        if(temp!=null)
            System.out.print("Deleted Element"+temp.data);
        temp=null;
        return head;
    }
    void display(node head)
    {
        System.out.print("Data=");
        if(head==null)
            System.out.print("No Element");
        while(head!=null)
        {
             System.out.print(head.data+" ");
             head=head.nxt;
        }
         System.out.println();
    }
}
class DLL
{
     public static void main(String argv[])
     {
        node head=null;
        operation ob=new operation();
        head=ob.createDLL(head);
        ob.display(head);
        System.out.println("Elements in DLL after delete:");
        head=ob.deleteNode(head);
        ob.display(head);

     }
}