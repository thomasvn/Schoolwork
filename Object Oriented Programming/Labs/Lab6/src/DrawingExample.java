import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * An example  to demonstrate various
 * drawing techniques including text, lines,
 * shapes, and filled shapes using Graphics2D.
 * Some of the notable 2D features:
 * Filling, Fonts, Printing,Shapes, Strokes and Transformations
 */
@SuppressWarnings("serial")
class Drawings2DSample extends JFrame {
	public Drawings2DSample(String titleText) {
		super(titleText);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		DrawingPanel dp = new DrawingPanel();
		getContentPane().add(dp, BorderLayout.CENTER);

		setLocationRelativeTo(null);
		setSize(500, 500);
		setVisible(true);
	}
}

/**
 * DrawingPanel setups the window and handles the drawings.
 */
@SuppressWarnings("serial")
class DrawingPanel extends JPanel {
	/**
	 * Class constructor. Actually sets the background and the border title.
	 */
	public DrawingPanel() {
		setBackground(Color.white);
		setBorder(BorderFactory.createTitledBorder("2D Graphics Example:"));
	}
	
	/**
	 * The paintComponent method is where all of your painting code should be placed.
	 * Do not call paintComponent() directly.
	 */
	public void paintComponent(Graphics gp) {
		super.paintComponent(gp);

		// Cast the graphics objects to Graphics2D
		Graphics2D g = (Graphics2D) gp;

		// Call method doDrawing and pass the Graphics2D object
		doDrawing(g);
	}

	/**
	 * Do the actual drawing.
	 * @param g
	 */
	private void doDrawing(Graphics2D g) {
		g.setStroke(new BasicStroke(5.0f));
		double startX = 50;
		double startY = 50;
		double endX = 100;
		double endY = 50;

		// Set the color
		g.setPaint(Color.blue);

		// Draw a Line
		Line2D line = new Line2D.Double(startX, startY, endX, endY);
		g.draw(line);
		startX = endX;
		startY = endY;
		endY += 50;
		// Draw another line
		g.setPaint(Color.magenta);
		Line2D line2 = new Line2D.Double(startX, startY, endX, endY);
		g.draw(line2);

		// Create a font object
		Font newFont = new Font("Verdana", Font.ITALIC, 30);
		g.setFont(newFont);
		Font cFont = g.getFont();

		String fontInfo = cFont.getName() + "  " + cFont.getStyle() + " " + cFont.getSize();
		// Draw a string of text
		g.drawString(fontInfo, (int) startX, (int) endY + 120);

		newFont = new Font("Comic Sans MS", Font.PLAIN, 20);
		g.setFont(newFont);
		g.setPaint(Color.BLACK);

		g.drawString("A Rectangle", (int) startX, (int) endY + 170);
		g.setPaint(Color.GREEN);
		double width = 100;
		double height = 80;

		// Draw a Rectangle
		Rectangle2D.Double rectangle = new Rectangle2D.Double(startX, endY + 200, width, height);
		g.draw(rectangle);

		g.setPaint(Color.blue);

		// Draw an oval
		Ellipse2D oval = new Ellipse2D.Double(startX + 130, endY + 200, 50, 75);
		g.fill(oval);
	}
}

/**
 * Main tester, creates Drawings2DSample which initiates a DrawingPanel objects which executes the graphics.
 */
public class DrawingExample {
	/**
	 * Main function.
	 * @param args
	 */
	public static void main(String[] args) {
		new Drawings2DSample("DrawingExample");
	}
}
