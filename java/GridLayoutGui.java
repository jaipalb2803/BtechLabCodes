import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class GridLayoutDemo extends JFrame
{
    JButton[] b=new JButton[10];
    GridLayoutDemo(){
        setSize(300,300);
        setLayout(new GridLayout(3,3,5,5));
        setTitle("GridLayoutDemo");
        for(int i=1;i<10;i++){
           b[i]=new JButton(Integer.toString(i));         
           add(b[i]);
        }
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    } 
}
class GridLayoutGui
{
    public static void main(String[] arg){
         new GridLayoutDemo();  
    }
}