import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Factorial extends JFrame implements ActionListener
{
    private JButton b;
	  private JLabel   l1,l2;
	  private JTextField t1,t2;
    private JPanel jp;
      Factorial(){
        setTitle("Factorial Frame");
        setSize(400,400);
        
        jp=new JPanel(new GridLayout(3,2));
        l1=new JLabel("Enter the Integer:");
        t1=new  JTextField();
        l2=new JLabel("Factorial Result:");
        t2=new  JTextField();
        b=new JButton("Compute");
        jp.add(l1);jp.add(t1);jp.add(l2);
        jp.add(t2);jp.add(b);
        //jp.setBounds(60,60,300,300);
        add(jp,BorderLayout.CENTER);
        b.addActionListener(this);
        pack();
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      }
      public void actionPerformed(ActionEvent e){
        try {
             int n = Integer.parseInt(t1.getText()),fact=1;
             for(int i=1;i<=n;i++)
                fact*=i;
             t2.setText(String.valueOf(fact));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(Factorial.this,"Invalid Entry");
        }
      }
}
class FactorialGui
{
    public static void main(String[] agv){
            new Factorial();
    }
}