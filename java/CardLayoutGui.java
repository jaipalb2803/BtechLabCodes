import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class CardLayoutDemo extends JFrame implements ActionListener
{
    JButton[] b=new JButton[6];
    CardLayout c;
    Container cP;
    CardLayoutDemo(){
        setSize(300,300);
        setTitle("CardLayoutDemo");
        cP=getContentPane();
        c=new CardLayout(20,20);
        cP.setLayout(c);
        for(int i=1;i<=5;i++){
           b[i]=new JButton("Button"+Integer.toString(i));         
           b[i].addActionListener(this);
           cP.add(b[i]);
        }
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

    } 
    public void actionPerformed(ActionEvent e)   
    {
         c.next(cP);
    }
}
class CardLayoutGui
{
    public static void main(String[] arg){
         new CardLayoutDemo();  
    }
}