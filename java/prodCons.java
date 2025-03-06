import java.util.*;
import java.io.*;
class buffer{
    private LinkedList<Integer> a;
    private int capacity;

    public buffer (int capacity){
        this.capacity=capacity;

        a=new LinkedList<>();
    }
    public synchronized void produce (int v)throws InterruptedException
    {
      
        while(a.size()==capacity){
            wait();
        }
      a.offer(v);
      System.out.println("Produced :"+v);
      notifyAll();
    }
    public synchronized void consume()throws InterruptedException
    {
         while(a.size()==0){
            wait();
        }
        int v=a.poll();
       System.out.println("consumed :"+v);
    }
}
class producer implements Runnable{
    private buffer b;
    private int c;

    public producer(buffer buff ,int count){
        b=buff;
        c=count;
    }
    public void run(){
        try{
            for(int i=0;i<c;i++){
                b.produce(i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
class consumer implements Runnable{
    private buffer b;                            
    private int c;
  
    public consumer(buffer buff ,int count){
        b=buff;
        c=count;
    }
    public void run(){
        try{                                              
            for(int i=0;i<c;i++){
                b.consume();
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
public class  prodCons{
    public static void main(String... agv){
        Scanner sc=new Scanner(System.in);                                             
        System.out.print("Enter Buffer capacity:");
        int n=sc.nextInt();

        buffer b=new buffer(n);
       /* System.out.print("size of Producer=");
        int a=sc.nextInt();

        System.out.print("size of consumer=");
        int c=sc.nextInt();*/
        
        producer pro=new producer(b,n);
        consumer con=new consumer(b,n);
        Thread pTh= new Thread(pro);
        Thread cTh= new Thread(con);
        pTh.start();
        cTh.start();
    }

}


