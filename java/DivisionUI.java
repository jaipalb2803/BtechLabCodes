import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DivisionUI {
    private JFrame frame;
    private JTextField num1Field;
    private JTextField num2Field;
    private JTextField resultField;
    private JButton divideButton;

    public DivisionUI() {
        frame = new JFrame("Integer Division");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel(new GridLayout(3, 2));

        JLabel num1Label = new JLabel("Num1:");
        num1Field = new JTextField();
        JLabel num2Label = new JLabel("Num2:");
        num2Field = new JTextField();
        JLabel resultLabel = new JLabel("Result:");
        resultField = new JTextField();
        resultField.setEditable(false);

        inputPanel.add(num1Label);
        inputPanel.add(num1Field);
        inputPanel.add(num2Label);
        inputPanel.add(num2Field);
        inputPanel.add(resultLabel);
        inputPanel.add(resultField);

        frame.add(inputPanel, BorderLayout.CENTER);

        divideButton = new JButton("Divide");
        divideButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                divideNumbers();
            }
        });

        frame.add(divideButton, BorderLayout.SOUTH);

        frame.pack();
        frame.setVisible(true);

    }
    private void divideNumbers() {
        try {
             float num1 = Float.parseFloat(num1Field.getText());
             float num2 = Float.parseFloat(num2Field.getText());

            float result = num1 / num2;
            resultField.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid input: Please enter integers only.", "Error",
                    JOptionPane.ERROR_MESSAGE);
        } catch (ArithmeticException ex) {
            JOptionPane.showMessageDialog(frame, "Division by zero error.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new DivisionUI();
            }
        });
    }
}
