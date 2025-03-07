import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class BorderLayoutDemo extends JFrame
{
    JButton[] b=new JButton[5];
    BorderLayoutDemo(){
        setSize(300,300);
        setTitle("BorderLayoutDemo");
        b[0]=new JButton("NORTH");    
        b[1]=new JButton("SOUTH");
        b[2]=new JButton("EAST");  
        b[3]=new JButton("WEST"); 
        b[4]=new JButton("CENTER");         
        setLayout(new BorderLayout(20,15));
        add(b[0],BorderLayout.NORTH);
        add(b[1],BorderLayout.SOUTH);
        add(b[2],BorderLayout.EAST);
        add(b[3],BorderLayout.WEST);
        add(b[4],BorderLayout.CENTER);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    } 
}
class BorderLayoutGui
{
    public static void main(String[] arg){
         new BorderLayoutDemo();  
    }
}