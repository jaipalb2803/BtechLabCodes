import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
class TrafficLights extends JFrame{
    TrafficLights(){
        setBounds(300,300,250,300);
        setTitle("TRAFFIC SIGNALS");
        JRadioButton jrb1=new JRadioButton("red");
        JRadioButton jrb2=new JRadioButton("Yellow");
        JRadioButton jrb3=new JRadioButton("Green");
        jrb1.setForeground(Color.red);
        jrb2.setBackground(Color.yellow);
        jrb3.setBackground(Color.green); 
        jrb1.setBounds(70,10,100,20);
        jrb2.setBounds(70,30,100,20);
        jrb3.setBounds(70,50,100,20);
        ButtonGroup b=new ButtonGroup();
        add(jrb1);
        add(jrb2);
        add(jrb3);
        b.add(jrb1);
        b.add(jrb2);
        b.add(jrb3);
        JButton jb=new JButton("Select");
        jb.setBounds(70,130,100,30);
        add(jb);
        jb.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                String q="";
                if(jrb1.isSelected())
                    q="STOP.";
                else if(jrb2.isSelected())
                    q="WAIT";
                else if(jrb3.isSelected())
                    q="GO.";
                else
                    q="SELECT BUTTON.";
                JOptionPane.showMessageDialog(TrafficLights.this,q);
            }
        });
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
class TrafficLightGui{
    public static void main(String[] args) {
        new TrafficLights();
    }
}