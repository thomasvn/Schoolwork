package lab1a;

/**
 * The Tester class is included in package lab1a to test the methods created in
 * Puppy.java
 * 
 * Answers to Questions: 
 * 1d) When I ran tester, I saw the correct name 
 * 1e) Yes! My getter for the age worked 
 * 1f) "Name not given yet"
 * 
 * @author thomasnguyen
 *
 */

public class Tester {
	public static void main(String[] args) {
		// Instance of Puppy using constructor to set name and age
		Puppy myPuppy = new Puppy("Waffles", 2);
		System.out.println("Puppy name: " + myPuppy.getName());
		System.out.println("Puppy age: " + myPuppy.getAge());

		// Instance of Puppy using constructor & setters
		Puppy myPuppy2 = new Puppy();
		myPuppy2.setName("ButterCup");
		myPuppy2.setAge(4);
		System.out.println("Puppy name: " + myPuppy2.getName());
		System.out.println("Puppy age: " + myPuppy2.getAge());
	}
}
