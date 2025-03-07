import java.util.Scanner;
import java.io.*;

class Sum
{
  
   
    public int sum(int x, int y)
    {
        return (x + y);
    }
  
    public int sum(int x, int y, int z)
    {
        return (x + y + z);
    }

    public double sum(double x, double y)
    {
        return (x + y);
    }
  
}

public class polyMorphm
{
  public static void main(String[] args) 
  {
    
        Sum s = new Sum();
        int x,y,z;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the X,Y,Z values:");
        x=sc.nextInt();
        y=sc.nextInt();
        z=sc.nextInt();
        
        System.out.println(s.sum(x, y));
        System.out.println(s.sum(x, y, z));
        System.out.println(s.sum(y, z));
  
  }
}