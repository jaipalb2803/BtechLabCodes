import javax.swing.*;
public class  swingJb{  

    JFrame f;
    swg_Jb()
    {
       f= new JFrame("Button Example");
       JButton b= new JButton("Click Here");

       b.setBounds(130,100,100,40);
       f.add(b);
       f.setSize(400,500);
       f.setLayout(null);
       f.setVisible(true);
       f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String args[])
    {  
       new swg_Jb();
    }
}

