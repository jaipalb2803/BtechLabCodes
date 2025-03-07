import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MouseEventDemo {
    private JFrame frame;
    private JLabel l;

    public MouseEventDemo()
    {
        frame = new JFrame("Mouse Event Demo");
        frame.setSize(400, 300);
        frame.setLayout(null);
        l = new JLabel();
        l.setBounds(120,100,200,30);
        //l.setHorizontalAlignment(SwingConstants.CENTER);
        l.setFont(new Font("Arial", Font.ITALIC & Font.BOLD , 18));

        frame.add(l, BorderLayout.CENTER);

        frame.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                l.setText("Mouse Clicked");
            }

            public void mousePressed(MouseEvent e) {
                l.setText("Mouse Pressed");
            }

            public void mouseReleased(MouseEvent e) {
                l.setText("Mouse Released");
            }

            public void mouseEntered(MouseEvent e) {
                l.setText("Mouse Entered");
            }

            public void mouseExited(MouseEvent e) {
                l.setText("Mouse Exited");
            }
        });

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {  
                new MouseEventDemo();
    }
}
