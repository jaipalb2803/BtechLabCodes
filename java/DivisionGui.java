import  javax.swing.*;
import  java.awt.*;
import  java.awt.event.*;

class  division extends JFrame {
		private JButton b;
		private JLabel   l1,l2,r;
		private JTextField t1,t2,t3;
		private int n1,n2;
		private String res;
		
          public division()
          {
          		setTitle("Division Frame");
          		setSize(400,400);
          		
          		l1=new JLabel("Num1 :");
				l1.setBounds(90,100,50,25);
          		l2=new JLabel("Num2 :");
				l2.setBounds(90,150,50,25);
          		r=new JLabel("Result:");
				r.setBounds(90,200,70,25);

          		t1=new JTextField();
				t1.setBounds(140,100,120,25);
          		t2=new JTextField ();
				t2.setBounds(140,150,120,25);
          		t3=new JTextField ("0");
				t3.setBounds(140,200,120,25);
          		b=new  JButton("Submit");
          		b.setBounds(90,300,100,25);
          		b.addActionListener(new ActionListener()
          		{ 
          		           public void actionPerformed(ActionEvent ae)
          		           {
          		           		n1=Integer.parseInt(t1.getText());
          		           		n2=Integer.parseInt(t2.getText());
          		           		res=Double.toString((double)n1/n2);
          		           		t3.setText(res); 		
          		           }
          		} );
          		add(l1); add(b);add(t1); add(t3);
          		add(l2); add(r);add(t2);          			
          		setLayout(null);
          		setVisible(true);
          		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
          }
}        
class  DivisionGui{
	public static  void  main(String[]  args){
	        new division(); 
	}
}