import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * In this class `MyArtWindow`, we instantiate the window which will pop up when
 * we run the program. We also add the Drawing Panel in which we have created
 * private methods to draw multiple faces and a staircase
 * 
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class MyArtWindow extends JFrame {
	/**
	 * The constructor `MyArtWindow`, instantiates the window
	 * 
	 * @param titleText
	 */
	public MyArtWindow(String titleText) {
		super(titleText);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		DrawingPanel dp = new DrawingPanel();
		getContentPane().add(dp, BorderLayout.CENTER);

		setLocationRelativeTo(null);
		setSize(700, 350);
		setVisible(true);
	}

	/**
	 * The `DrawingPanel` class is simply a panel in the JFrame. Inside this
	 * class, we also have methods to paint the faces and staircases
	 * 
	 * @author ThomasNguyen
	 */
	class DrawingPanel extends JPanel {
		public DrawingPanel() {
			setBackground(Color.white);
			setBorder(BorderFactory.createTitledBorder("2D Graphics Example:"));
		}

		/**
		 * This is our driver method that messages `drawFace()` and
		 * `drawStaircase` with the proper configurations
		 */
		public void paintComponent(Graphics gp) {
			double startX, startY, width, height;
			Boolean reverse;

			super.paintComponent(gp);

			// Cast the graphics objects to Graphics2D
			Graphics2D g = (Graphics2D) gp;

			// Draws 5 Faces
			startX = 20;
			startY = 30;
			for (int i = 0; i < 5; i++) {
				this.drawFace(g, startX, startY);
				startX += 110;
			}

			// Draws the staircases
			startX = 10;
			startY = 150;
			width = 10;
			height = 10;
			reverse = false;
			this.drawStairase(g, startX, startY, width, height, reverse);

			// Draws the reverse staircases
			startX = 150;
			startY = 150;
			width = 100;
			height = 10;
			reverse = true;
			this.drawStairase(g, startX, startY, width, height, reverse);
		}

		/**
		 * This method draws a single face given a starting position. Within the
		 * method, it first draws the head, then the eyes, then the mouth.
		 * 
		 */
		private void drawFace(Graphics2D g, double startX, double startY) {
			// Head: Circle 100px Diameter @ Top Left Corner (20,30)
			Ellipse2D circle = new Ellipse2D.Double(startX, startY, 100, 100);
			g.setPaint(Color.black);
			g.draw(circle);

			// Eyes: Blue Circles 20px Diameter (Position Appropriately)
			Ellipse2D eye1 = new Ellipse2D.Double(startX + 20, startY + 25, 20, 20);
			Ellipse2D eye2 = new Ellipse2D.Double(startX + 57.5, startY + 25, 20, 20);
			g.setPaint(Color.blue);
			g.draw(eye1);
			g.draw(eye2);
			g.fill(eye1);
			g.fill(eye2);

			// Mouth: Red Line (Choose Start and End)
			Line2D mouth = new Line2D.Double(startX + 30, startY + 70, startX + 70, startY + 70);
			g.setPaint(Color.red);
			g.draw(mouth);
			g.fill(mouth);
		}

		/**
		 * This method draws a single staircase given the starting position,
		 * initial size of a rectangle, and whether the staircase should be
		 * reversed. Given that we create a staircase with 10 steps.
		 * 
		 * @param g
		 */
		private void drawStairase(Graphics2D g, double startX, double startY, double width, double height,
				Boolean reverse) {
			g.setPaint(Color.black);

			// 10 Steps for the staircase
			for (int i = 0; i < 10; i++) {
				// Create this iteration's step in the staircase
				Rectangle2D.Double rectangle = new Rectangle2D.Double(startX, startY, width, height);
				g.draw(rectangle);

				// Increment starting position of next iteration's staircase
				startY += 10;

				// Changes width based on the whether staircase needs to be
				// reversed
				if (!reverse) {
					width += 10;
				} else {
					width -= 10;
				}
			}
		}
	}
}

/**
 * This is our driver method to effectively message all the functions necessary
 * to draw the faces and staircases
 * 
 * @author ThomasNguyen
 */
public class MyArtDemo {
	/**
	 * This is our main driver method which instantiates a `MyArtWindow` object
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		new MyArtWindow("MyArt - Thomas Nguyen");
	}
}