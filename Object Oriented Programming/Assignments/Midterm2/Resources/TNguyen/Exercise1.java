package midterm2;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

/**
 * This class is our GUI which includes two buttons. Our `change` button will be
 * able to change the state of our `trafficLightButton` button.
 * 
 * @author thomasnguyen
 *
 */
@SuppressWarnings("serial")
class TrafficLight extends JFrame implements ActionListener {
	private JButton trafficLightButton, change;
	private String colorState;
	private final int WINDOW_WIDTH = 500;
	private final int WINDOW_HEIGHT = 300;

	public TrafficLight(String title) {
		super(title);

		// Set up the GUI
		JFrame frame = new JFrame("Traffic Light");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container container = frame.getContentPane();
		frame.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		frame.setVisible(true);
		container.setLayout(null);

		// Set up our Traffic Light Button
		trafficLightButton = new JButton();
		trafficLightButton.setText("State of Traffic Light");
		trafficLightButton.setBounds((WINDOW_WIDTH - 200) / 2, 10, 200, 120);
		trafficLightButton.setOpaque(true);
		container.add(trafficLightButton);

		// Set the default state of the Traffic Light Button
		trafficLightButton.setBackground(Color.RED);
		colorState = "RED";

		// Set up our second button to change the state of the traffic light
		change = new JButton("Change");
		change.setText("Change State of Traffic Light");
		change.setBounds((WINDOW_WIDTH - 200) / 2, 150, 200, 120);
		change.addActionListener(this);
		container.add(change);
	}

	/**
	 * This method is messaged when the `change` button is clicked. It changes
	 * the background color of the Button
	 * 
	 * @param e
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		if (colorState == "RED") {
			colorState = "GREEN";
			trafficLightButton.setBackground(Color.GREEN);
		} else if (colorState == "YELLOW") {
			colorState = "RED";
			trafficLightButton.setBackground(Color.RED);
		} else if (colorState == "GREEN") {
			colorState = "YELLOW";
			trafficLightButton.setBackground(Color.YELLOW);
		}
	}
}

/**
 * This is our driver class which instantiates the Traffic Light class
 * 
 * @author thomasnguyen
 *
 */
public class Exercise1 {
	public static void main(String[] args) {
		new TrafficLight("Traffic Light");
	}
}