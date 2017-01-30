package edu.scu.coen160.lab2;

/**
 * Exercise3.java
 * 
 * This exercise uses the Math.random() method to generate random numbers
 * 
 * @author thomasnguyen
 *
 */

class RandomNumbers {
	public static void genRandNum(int range, int count) {
		// The Math.random() method returns random double numbers
		// in the range >=0.0 to <1.0 .
		
		for (int i = 0; i < range; i++) {
			int rand = (int) (range * Math.random());
			System.out.println(rand);
		}
		
	}
}

public class Exercise3 {
	public static void tester() {
		// Generate 10 numbers in the range of 0-10
		RandomNumbers.genRandNum(11, 10);
	}
}