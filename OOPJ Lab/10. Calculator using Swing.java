import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorSwing extends JFrame implements ActionListener {
    JTextField t;
    JButton b0, b1, b2, b3, b4, b5, b6, b7, b8, b9;
    JButton bMinus, bPlus, bDivide, bMultiply, bDot, bEquals, bClear;
    double val1 = 0, val2 = 0, choice = 0, result = 0;
    String operator, s;
    boolean flag = true;

    public CalculatorSwing() {
        JFrame frame = new JFrame("CALCULATOR");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        frame.setLayout(layout);
        t = new JTextField(10);
        t.setText("");
        t.setEditable(false);
        b0 = new JButton("0");
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        bPlus = new JButton("+");
        bMinus = new JButton("-");
        bDivide = new JButton("/");
        bMultiply = new JButton("*");
        bDot = new JButton(".");
        bEquals = new JButton("=");
        bClear = new JButton("c");
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        bPlus.addActionListener(this);
        bMinus.addActionListener(this);
        bDivide.addActionListener(this);
        bMultiply.addActionListener(this);
        bDot.addActionListener(this);
        bEquals.addActionListener(this);
        bClear.addActionListener(this);
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3;
        gbc.gridx = 0;
        gbc.gridy = 0;
        frame.add(t, gbc);
        gbc.gridwidth = 1;
        gbc.gridx = 3;
        gbc.gridy = 0;
        frame.add(bEquals, gbc);
        gbc.gridx = 0;
        gbc.gridy = 1;
        frame.add(b1, gbc);
        gbc.gridx = 1;
        gbc.gridy = 1;
        frame.add(b2, gbc);
        gbc.gridx = 2;
        gbc.gridy = 1;
        frame.add(b3, gbc);
        gbc.gridx = 3;
        gbc.gridy = 1;
        frame.add(bPlus, gbc);
        gbc.gridx = 0;
        gbc.gridy = 2;
        frame.add(b4, gbc);
        gbc.gridx = 1;
        gbc.gridy = 2;
        frame.add(b5, gbc);
        gbc.gridx = 2;
        gbc.gridy = 2;
        frame.add(b6, gbc);
        gbc.gridx = 3;
        gbc.gridy = 2;
        frame.add(bMinus, gbc);
        gbc.gridx = 0;
        gbc.gridy = 3;
        frame.add(b7, gbc);
        gbc.gridx = 1;
        gbc.gridy = 3;
        frame.add(b8, gbc);
        gbc.gridx = 2;
        gbc.gridy = 3;
        frame.add(b9, gbc);
        gbc.gridx = 3;
        gbc.gridy = 3;
        frame.add(bDivide, gbc);
        gbc.gridx = 0;
        gbc.gridy = 4;
        frame.add(bDot, gbc);
        gbc.gridx = 1;
        gbc.gridy = 4;
        frame.add(b0, gbc);
        gbc.gridx = 2;
        gbc.gridy = 4;
        frame.add(bClear, gbc);
        gbc.gridx = 3;
        gbc.gridy = 4;
        frame.add(bMultiply, gbc);
        frame.setSize(200, 200);
        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        String temp = ae.getActionCommand();
        if (('0' <= temp.charAt(0) && temp.charAt(0) <= '9') || temp.equals(".")) {
            t.setText(t.getText() + temp);
        } else if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
            t.setText(t.getText() + temp);
            operator = temp;
        } else if (temp == "=") {
            s = "\\" + operator;
            System.out.println(s);
            String str[] = t.getText().split(s);
            val1 = Double.parseDouble(str[0]);
            val2 = Double.parseDouble(str[1]);
            try {
                switch (operator) {
                    case "+":
                        result = val1 + val2;
                        break;
                    case "-":
                        result = val1 - val2;
                        break;
                    case "/":
                        result = val1 / val2;
                        break;
                    case "*":
                        result = val1 * val2;
                        break;
                }
            } catch (Exception e) {
                System.out.println(e);
            }
            String r = String.format("%.4f", result);
            t.setText(t.getText() + "=" + r);
        } else if (temp == "c") {
            t.setText("");
        }
    }

    public static void main(String args[]) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new CalculatorSwing();
            }
        });
    }
}
