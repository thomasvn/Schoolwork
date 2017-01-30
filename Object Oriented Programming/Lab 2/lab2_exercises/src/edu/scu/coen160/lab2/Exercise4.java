package edu.scu.coen160.lab2;
import java.util.Random;

/**
 * Exercise4.java
 * 
 * This exercise also randomly generates numbers but utilizes the Java Random API
 * 
 * Questions:
 * a) randomGen.nextInt()/range is the equivalent to Math.random()
 * b) 10 would not be included in the numbers generated
 * 
 * @author thomasnguyen
 *
 */
class RandomNumbers2 {
	public static void genRandNum(int range, int count){
		// Create an instance of Random() and call the nextInt(range) method
		// to generate numbers in that range.
		Random randomGen = new Random();
		
		for (int i = 0; i < range; i++) {
			System.out.println(randomGen.nextInt(range)); 
		}
		
	}
}

public class Exercise4 {
    public static void tester () {
    	// Generate 10 numbers in the range of 0-10
     	RandomNumbers2.genRandNum(11,10);
    }
}