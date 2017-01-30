package lab1b;

/**
 * This PatternMaker class contains two classes to draw different patterns.
 * 
 * Answer to Question: We did not need to create an instance of PatternMaker to
 * message its methods because the methods were static.
 * 
 * @author thomasnguyen
 *
 */

class PatternMaker {
	// This method draws a symbol a specified number of times after a specified
	// offset
	public static void drawOneLine(char symbol, int noOfTimes, int offset) {
		// Write Java code to draw the symbol for the noOfTimes
		// after drawing a number of blankspaces (offset) .
		// For example, if the symbol is "*", noOfTimes is 10
		// and offset is 3,it should draw 3 blank spaces and
		// then draw 10 stars.
		// System.out.print(); // This will print on the same line
		// System.out.println(); // This will start the drawing on a new line.
		// Write a for – loop to draw offset number of blank spaces.
		// for example, if offset is 3, it should draw 3 blank spaces.
		// Use System.out.print(” ”) to print a single blank space.
		// Write a for – loop to draw the symbol, the noOfTimes.

		for (int i = 0; i < offset; i++) {
			System.out.print(" ");
		}

		for (int i = 0; i < noOfTimes; i++) {
			System.out.print(symbol);
		}

		System.out.println();
	}

	// This method draws a specific pattern as specified in the instructions
	// below
	public static void drawPattern() {
		/*
		 * This method should draw the following pattern, where the first line,
		 * should have 5 blank spaces followed by 5 stars, second line will have
		 * 10 blank spaces followed by 10 stars and the last line will have 15
		 * blank spaces followed by 15 stars.
		 *****
		 *********
		 *************
		 * The method should call the method, drawOneLine() with the correct
		 * number of values for parameters. For example, the first call to
		 * drawOneLine() is drawOneLine (‘*’, 5, 5);
		 */

		PatternMaker.drawOneLine('*', 5, 5);
		PatternMaker.drawOneLine('*', 10, 10);
		PatternMaker.drawOneLine('*', 15, 15);
	}

	// This main function tests our two functions in this class
	public static void main(String[] args) {
		PatternMaker.drawOneLine('+', 12, 6);
		PatternMaker.drawPattern();
	}
}