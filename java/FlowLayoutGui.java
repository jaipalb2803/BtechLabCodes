import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class FlowLayoutDemo extends JFrame
{
    JButton[] b=new JButton[10];
    FlowLayoutDemo(){
        setSize(300,300);
        setTitle("FlowLayoutDemo");
        for(int i=1;i<10;i++){
           b[i]=new JButton(Integer.toString(i));         
           add(b[i]);
        }
        setLayout(new FlowLayout(FlowLayout.CENTER,3,3));
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    } 
}
class FlowLayoutGui
{
    public static void main(String[] arg){
         new FlowLayoutDemo();  
    }
}