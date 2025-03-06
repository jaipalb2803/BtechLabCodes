import java.io.*;

class DisplayFileExample
{
   void printFileNames(File[] a, int i, int j)
   {
        while(i!=a.length)
        {
          if(a[i].isFile())
            System.out.println(a[i].getName());
         //printFileNames(a,i+1,j);
          i++;
        }
   }
}
class DisplayFiles
{
     public static void main(String argv[])
     {
          String path="C:\\Documents\\java";

          File fObj=new File(path);
          DisplayFileExample obj=new DisplayFileExample();
        
          if(fObj.exists() && fObj.isDirectory())
          {
             File a[]=fObj.listFiles();
             System.out.println("Display file from directory:");
             obj.printFileNames(a,0,0);
          }
          
     }
}