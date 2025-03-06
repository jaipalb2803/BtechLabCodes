import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TableDisplay {
    private JFrame frame;
    private JPanel panel;
    JLabel label ;

    public TableDisplay() {
        frame = new JFrame("Table Display");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel(new GridLayout(0, 3)); // Assuming 3 columns for the table

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }

    public void displayTable(String filename) {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] elements = line.split(",");
                for (String ele : elements) {
                    label = new JLabel(ele);
                    panel.add(label);
                }
            }

            frame.revalidate();
            frame.repaint();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        TableDisplay tableDisplay = new TableDisplay();
        tableDisplay.displayTable("sample.txt"); // Provide the path to your table file
    }
}
