package edu.scu.coen160.lab5;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

/**
 * In this exercise, we continued working with the event listener to change text
 * displayed based on the input received
 * 
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class WorkExperience extends JFrame implements ActionListener {
	// Declarations
	private JTextField nameFld, workFld;
	private JLabel label1, label2, levelLabel;

	/**
	 * This is the constructor for the AWT which creates and formats our window
	 */
	public WorkExperience() {
		super("WorkExperience");
		setSize(500, 100);

		Container container = getContentPane();
		container.setLayout(new FlowLayout());
		label1 = new JLabel("Your name:", JLabel.CENTER);
		container.add(label1);
		nameFld = new JTextField(10);

		container.add(nameFld);

		label2 = new JLabel("Work Exp:", JLabel.CENTER);
		container.add(label2);
		workFld = new JTextField(10);

		// Capture the event where user hits Enter key
		workFld.addActionListener(this);
		container.add(workFld);

		levelLabel = new JLabel("", JLabel.RIGHT);
		container.add(levelLabel);

		// Show the frame in the center of the screen
		setLocationRelativeTo(null);
		setVisible(true);
	}

	/**
	 * This method is messaged when passing the `WorkExperience` class and
	 * calling `.addActionListener()`. In this method we display "Junior" or
	 * "Senior" based on work experience specified by the user
	 */
	public void actionPerformed(ActionEvent e) {
		// Complete the method
		if (e.getSource() == workFld) {
			// Get the input from the textfield
			String input = workFld.getText();

			try {
				// Change String to Integer
				int result = Integer.parseInt(input);

				// If years entered are <= 5 then it is a Junior. Else it is a
				// Senior.
				if (result <= 5) {
					levelLabel.setText("Junior");
				} else {
					levelLabel.setText("Senior");
				}

			} catch (NumberFormatException ex) {
				JOptionPane.showMessageDialog(null, "Please type in a valid integer");
			}
		}
	}
}

/**
 * This is our driver class for Exercise 2.
 * 
 * @author ThomasNguyen
 */
public class Exercise2 {
	public static void main(String[] args) {
		// Run the GUI codes on Event-Dispatching thread for thread safety
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new WorkExperience();
			}
		});
	}
}
