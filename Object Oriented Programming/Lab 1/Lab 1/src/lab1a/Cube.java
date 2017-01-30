package lab1a;

/**
 * The Cube class is initially had syntactical and logical errors in its code.
 * The version seen below has been fixed
 * 
 * @author thomasnguyen
 *
 */

public class Cube {
	// Our main method calculates the volume of a cube when a height is
	// specified
	public static void main(String[] args) {
		double height = 3.0; // inches
		double cube_volume = height * height * height;
		System.out.println("Volume = " + cube_volume);
	}
}
