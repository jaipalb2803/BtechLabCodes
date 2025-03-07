
class Thread1 implements Runnable
{
     public void run()
     {
          for(int i=0;i<3;i++)
             System.out.println("Thread1 =>"+i);
          System.out.println("Thread1-->Exits");
     }
}
class Thread2 implements Runnable
{
     public void run()
     {
          for(int i=0;i<3;i++)
             System.out.println("Thread2 =>"+i);
          System.out.println("Thread2-->Exits");
     }
}
class Thread3 implements Runnable
{
     public void run()
     {
          for(int i=0;i<3;i++)
             System.out.println("Thread3 =>"+i);
          System.out.println("Thread3-->Exits");
     }
}
class MultThrdWithRunnable
{
     public static void main(String... argv){
          
          Thread1 a=new Thread1();
          Thread t1=new Thread(a);

          Thread t2=new Thread(new Thread2());
          Thread t3=new Thread(new Thread3());

          t1.start();
          t2.start();
          t3.start();
          System.out.println("MultiThreading is over...");


     }

}