class Thread1 extends Thread
{
      public void run()
      {
          for(int i=0;i<3;i++){
               System.out.println("Thread->1");
          }
          System.out.println("Thread->1 is Exits");
      }
}
class Thread2 extends Thread
{
      public void run()
      {
          for(int i=0;i<3;i++){
               System.out.println("Thread->2");
          }
          System.out.println("Thread->2 is Exits");
      }
}
class Thread3  extends Thread
{
      public void run()
      {
          for(int i=0;i<3;i++){
               System.out.println("Thread->3");
          }
          System.out.println("Thread->3 is Exits");
      }
}
class MultiThreading
{
     public static void main(String... argv){
          Thread1 a=new Thread1();
          Thread2 b=new Thread2();
          Thread3 c=new Thread3();

          a.start();
          b.start();
          c.start();
          System.out.println("MultiThreading is over...");

     }

}