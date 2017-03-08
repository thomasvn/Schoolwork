package edu.scu.coen160.lab5;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

/**
 * In this exercise, we received an introduction to how the AWT(Abstract Window
 * Toolkit) works by centering the popup panel. We also took the input from the
 * user and changed all values to upper case.
 * 
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class TextFieldDemo extends JFrame implements ActionListener {
	// Declarations
	private JTextField nameFld, resultFld;
	private JLabel label1, label2;

	/**
	 * This is the constructor for the AWT which creates and formats our window
	 */
	public TextFieldDemo() {
		super("TextField  Demo");
		setSize(500, 100);

		Container container = getContentPane();
		container.setLayout(new FlowLayout());

		label1 = new JLabel("Your name:", JLabel.CENTER);
		container.add(label1);
		nameFld = new JTextField(10);

		// Capture the event where user hits Enter key
		nameFld.addActionListener(this);
		container.add(nameFld);

		label2 = new JLabel("Name in Uppercase:", JLabel.CENTER);
		container.add(label2);
		resultFld = new JTextField(10);
		resultFld.setEditable(false); // User cannot enter input in this field

		container.add(resultFld);
		setVisible(true);

		// Set Relative Location
		setLocationRelativeTo(null);
	}

	/**
	 * This method is messaged when passing the `TextFieldDemo` class and
	 * calling `.addActionListener()`. In this method we changed the input to
	 * all upper case characters
	 */
	public void actionPerformed(ActionEvent e) {
		// When the user enters a value and hits "Enter" in the nameFld
		if (e.getSource() == nameFld) {
			// Get the input from the textfield
			String input = nameFld.getText();

			// Convert the input to upper case and write it in the resultFld
			input = input.toUpperCase();
			resultFld.setText(input);
		}
	}
}

/**
 * This is our driver class for Exercise 1.
 * 
 * @author ThomasNguyen
 */
public class Exercise1 {
	/**
	 * Main driver method of our driver class
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		/**
		 * Run the GUI codes on Event-Dispatching thread for thread safety
		 */
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				TextFieldDemo test = new TextFieldDemo();
				test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			}
		});
	}
}