import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class TrafficLight extends JFrame implements ActionListener {
 JRadioButton r1, r2, r3;
 TrafficLight() {
 r1 = new JRadioButton("Red");
 r2 = new JRadioButton("Yellow");
 r3 = new JRadioButton("Green");
 r1.setBounds(100, 200, 100, 30);
 r2.setBounds(100,250, 100, 30);
 r3.setBounds(100, 300, 100, 30);
 ButtonGroup bg = new ButtonGroup();
 bg.add(r1);
 bg.add(r2);
 bg.add(r3);
 r1.addActionListener(this);
 r2.addActionListener(this);
 r3.addActionListener(this);
 add(r1);
 add(r2);
 add(r3);
 setSize(900, 800);
 setLayout(null);
 setVisible(true);
 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }
 public void paint(Graphics g) {
 g.setColor(Color.black);
 g.drawRect(550, 100, 200, 600);
 g.setColor(Color.black);
 g.drawOval(600, 150, 100, 100);
 g.drawOval(600, 350, 100, 100);
 g.drawOval(600, 550, 100, 100);
 g.setColor(Color.white);
 g.fillOval(600, 150, 100, 100);
 g.fillOval(600, 350, 100, 100);
 g.fillOval(600, 550, 100, 100);
 if (r1.isSelected()) {
 g.setColor(Color.red);
 g.fillOval(600, 150, 100, 100);
 }
 if (r2.isSelected()) {
 g.setColor(Color.yellow);
 g.fillOval(600, 350, 100, 100);
 }
 if (r3.isSelected()) {
 g.setColor(Color.green);
 g.fillOval(600, 550, 100, 100);
 }
 }
 public void actionPerformed(ActionEvent ae) {
 repaint();
 }
 public static void main(String[] args) {
 SwingUtilities.invokeLater(new Runnable() {
 public void run() {
 new TrafficLight();
 }
 });
 }
}
