import javax.swing.*;
import java.awt.*;  
import java.awt.event.*;

class calculator  extends JFrame implements ActionListener  
{  
   JTextField t1;
   JButton[] numB=new JButton[10];
   JButton[] funB=new JButton[8];
   JButton addB,subB,multB,divB,decB,equB,delB,clrB;
   JPanel panel;

   Font myFont=new Font("Ink Free",Font.BOLD,30);
   double n1=0,n2=0,res=0;
   char opr;

   public calculator() {  
   
      setTitle("Calculator");
      setLayout(null);  
      setSize(420,550);
      t1=new JTextField();
      t1.setBounds(50,23,300,50);
      t1.setFont(myFont);
      t1.setEditable(false);

      addB=new JButton("+");
      subB=new JButton("-");
      multB=new JButton("*");
      divB=new JButton("/");
      decB=new JButton(".");
      equB=new JButton("=");
      delB=new JButton("Delete");
      clrB=new JButton("clear");
      
      funB[0]=addB;funB[1]=subB;
      funB[2]=multB;funB[3]=divB; 
      funB[4]=decB; funB[5]=equB;
      funB[6]=delB; funB[7]=clrB;

      for(int i=0;i<8;i++){
        funB[i].addActionListener(this);
        funB[i].setFont(myFont);
        funB[i].setFocusable(false);

      }
      for(int i=0;i<10;i++){
        numB[i]=new JButton(String.valueOf(i));
        numB[i].addActionListener(this);
        numB[i].setFont(myFont);
        numB[i].setFocusable(false);
      }
      delB.setBounds(50,430,145,50);
      clrB.setBounds(200,430,145,50);
      panel=new JPanel(new GridLayout(4,4,10,10));
      for(int i=1;i<10;i++){
        if(i==4) panel.add(addB);
        if(i==7) panel.add(subB);
        panel.add(numB[i]);
      }
      panel.add(multB);
      panel.add(decB);
      panel.add(numB[0]);
      panel.add(equB);
      panel.add(divB);
      
      panel.setBounds(50,100,300,300);
      panel.setBackground(Color.GRAY);

      add(panel,BorderLayout.CENTER);
      add(delB);
      add(clrB);
      add(t1);  
      setVisible(true);
      setDefaultCloseOperation(EXIT_ON_CLOSE);  
  }  
  public void actionPerformed(ActionEvent e)
  {
       for(int i=0;i<10;i++){
         if(e.getSource()==numB[i]){
            t1.setText(t1.getText().concat(String.valueOf(i)));
         }
       }
       if(e.getSource()==decB){
            t1.setText(t1.getText().concat("."));
        }
        if(e.getSource()==addB){
            t1.setText(t1.getText().concat("+"));
            opr='+';
        }
        if(e.getSource()==subB){
            t1.setText(t1.getText().concat("-"));
            opr='-';
        }
        if(e.getSource()==multB){
            t1.setText(t1.getText().concat("*"));
            opr='*';   
        }
        if(e.getSource()==divB){
            t1.setText(t1.getText().concat("/"));
            opr='/';
        }
        if(e.getSource()==equB){
            String str=t1.getText();
            String[] num=str.split("[+\\-\\*\\/]");
            n1=Double.parseDouble(num[0]);
            n2=Double.parseDouble(num[1]);
            switch (opr) {
            case '+':res=n1 + n2;
                break;
            case '-':res=n1 - n2;
                  break;
             case '*':res=n1*n2;
                 break;
            case '/':res=n1 / n2;
                  break;
            default:
              throw new IllegalArgumentException("Invalid operator");
           }
            t1.setText(String.valueOf((float)res));
        }
        if(e.getSource()==clrB){
            t1.setText("");
        }
        if(e.getSource()==delB){
            String str=t1.getText();
            t1.setText("");
            for(int i=0;i<str.length()-1;i++){
               t1.setText(t1.getText()+str.charAt(i));  
            }

        }
   }   
}
class calciGui
{
    public static void main(String[] args) {  
      calculator calc=new calculator();  
  } 
}  