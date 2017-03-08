package edu.scu.coen160.lab5;

import java.awt.BorderLayout;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
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
 * In this exercise, we were asked to implement a BMI Calculator with less
 * assistance than given before. Therefore we needed to instantiate the
 * necessary objects and format the window pane properly.
 *
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class BMICalculator extends JFrame implements ActionListener {
	// Declarations
	private JTextField height_feet, height_inches, weight;
	protected JLabel label1, label2, label3, bmi;
	private JButton calculateButton;
	private JPanel panel1, panel2;

	/**
	 * This is the constructor for the AWT which creates and formats our window.
	 * It is formatted similar to previous exercises but uses different text
	 * fields
	 */
	public BMICalculator() {
		super("BMICalculator");
		setSize(500, 100);

		Container container = getContentPane();
		container.setLayout(new FlowLayout());

		panel1 = new JPanel();

		label1 = new JLabel("Height(feet):", JLabel.CENTER);
		panel1.add(label1);
		height_feet = new JTextField(5);
		panel1.add(height_feet);

		label2 = new JLabel("Height(inches):", JLabel.CENTER);
		panel1.add(label2);
		height_inches = new JTextField(5);
		panel1.add(height_inches);

		label3 = new JLabel("Weight(lbs):", JLabel.CENTER);
		panel1.add(label3);
		weight = new JTextField(5);
		panel1.add(weight);

		bmi = new JLabel("BMI:", JLabel.CENTER);
		panel1.add(bmi);

		panel2 = new JPanel();
		calculateButton = new JButton("Calculate BMI");
		panel2.add(calculateButton);

		calculateButton.addActionListener(this);

		container.add(panel1, BorderLayout.NORTH);
		container.add(panel2, BorderLayout.SOUTH);

		// show the frame in the center of the screen
		setLocationRelativeTo(null);
		setVisible(true);
	}

	/**
	 * This method is messaged when passing the `BMICalculator` class and
	 * calling `.addActionListener()`. In this method we display calculate the
	 * BMI and display the results to our client. We also change the color of
	 * the background if the BMI is out of a "healthy" range
	 */
	public void actionPerformed(ActionEvent e) {
		// Get the input from the textfield
		String height_feet_input = height_feet.getText();
		String height_inches_input = height_inches.getText();
		String weight_input = weight.getText();

		try {
			// Change String to Integer
			double feet = Double.parseDouble(height_feet_input);
			double inches = Double.parseDouble(height_inches_input);
			double lbs = Double.parseDouble(weight_input);

			// Calculate BMI
			double total_height = (feet * 12) + inches;
			lbs = lbs * 0.45;
			total_height = total_height * .025;
			total_height = total_height * total_height;

			double bmi_result = lbs / total_height;

			// Change color of panel if BMI is out of range
			if (bmi_result < 18.5 || bmi_result > 24.9) {
				panel1.setBackground(Color.RED);
			}

			bmi_result = Math.round(bmi_result);

			// Set text of Celsius
			String result = "BMI: ";
			result = result + Double.toString(bmi_result);
			bmi.setText(result);

		} catch (NumberFormatException ex) {
			JOptionPane.showMessageDialog(null, "Please type in a valid number");
		}
	}
}

/**
 * This is our driver class which instantiates `BMICalculator()` utility.
 *
 * @author
 */
public class Exercise4 {
	public static void main(String[] args) {
		// Run the GUI codes on Event-Dispatching thread for thread safety
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new BMICalculator();
			}
		});
	}
}
