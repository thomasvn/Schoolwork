package edu.scu.coen160.lab5;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

/**
 * In this exercise, we continued working with the AWT by adding an event
 * listener and implementing the conversion between Farenheit to Celsius
 *
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class TempConverter extends JFrame {
	// Declarations
	private JTextField fahrenFld;
	protected JLabel label1, celsius;
	private JButton convertButton;
	private JPanel panel1, panel2;

	/**
	 * This is the constructor for the AWT which creates and formats our window
	 */
	public TempConverter() {
		super("Temperature Converter");
		setSize(500, 150);

		Container container = getContentPane();
		container.setLayout(new BorderLayout());

		panel1 = new JPanel();
		panel1.setBackground(Color.YELLOW);

		label1 = new JLabel("Fahrenheit:", JLabel.CENTER);
		panel1.add(label1);
		fahrenFld = new JTextField(10);
		panel1.add(fahrenFld);

		celsius = new JLabel("Celsius:", JLabel.CENTER);
		panel1.add(celsius);

		panel2 = new JPanel();
		convertButton = new JButton("ToCelsius");
		panel2.add(convertButton);

		// This statement instantiates our Converter class and adds a listener
		// to the `convertButton`
		convertButton.addActionListener(new Converter(this));

		container.add(panel1, BorderLayout.NORTH);
		container.add(panel2, BorderLayout.SOUTH);

		// Show the frame in the center of the screen
		setLocationRelativeTo(null);
		setVisible(true);
	}

	/**
	 * This `Converter` class implements the `ActionListener` template. We will
	 * be using this class to convert Fahrenheit to Celsius
	 *
	 * @author ThomasNguyen
	 */
	private class Converter implements ActionListener {
		private TempConverter tempConverter = null;

		/**
		 * This constructor assigns our `TempConverter` class pointer to the
		 * `TempConverter` class passed in the constructor.
		 *
		 * @param tempConverter
		 */
		public Converter(TempConverter tempConverter) {
			this.tempConverter = tempConverter;
		}

		/**
		 * This method is messaged when passing the `Converter` class and
		 * calling `.addActionListener()`. In this method we convert a given
		 * integer for Fahrenheit to Celsius
		 */
		public void actionPerformed(ActionEvent e) {
			// Get the input from the textfield
			String input = fahrenFld.getText();

			try {
				// Change String to Integer
				int fahrenheit_input = Integer.parseInt(input);

				// Calculate Celsius using Fahrenheit
				int celsius_result = (fahrenheit_input - 32) * 5 / 9;
				celsius_result = Math.round(celsius_result);

				// Change Integer back to string and format text
				String result = "Celsius: ";
				result = result + Integer.toString(celsius_result);
				result = result + " degrees";

				// Set text of Celsius
				celsius.setText(result);

			} catch (NumberFormatException ex) {
				JOptionPane.showMessageDialog(null, "Please type in a valid number");
			}
		}
	}
}

/**
 * This is our driver class for Exercise 3.
 *
 * @author ThomasNguyen
 */
public class Exercise3 {
	/**
	 * This is our driver method in which we instantiate our `TempConverter`
	 *
	 * @param args
	 */
	public static void main(String[] args) {
		// Run the GUI codes on Event-Dispatching thread for thread safety
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new TempConverter();
			}
		});
	}
}
