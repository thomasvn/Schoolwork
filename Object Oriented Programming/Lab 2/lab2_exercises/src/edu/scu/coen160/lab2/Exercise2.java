package edu.scu.coen160.lab2;

import java.lang.String;

/**
 * Exercise2.java
 * 
 * This exercise includes two string exercises. The first string exercise formats
 * a full name given the proper parameters. The second exercise checks to see if
 * an inputed string is a palindrome.
 * 
 * Additionally, there is a class called `Exercise2` which acts as the tester.
 * 
 * @author thomasnguyen
 *
 */

class StringExercise {
	public static String fullName(String firstName, String middleName, String lastName) {
		// Create a string for full name as lastName, firstName,first letter of
		// middle name followed by a . (dot). The first initials of first and
		// last names and the middle initial should be in upper case and the rest in
		// lower case.
		// 
		// For example, Robert (first), alan (middle) and Smith (last) should be
		// written as Smith, Robert A.
		// 
		// Return the full name.
		
		String fullName;

		StringBuffer buff1 = new StringBuffer();
		buff1.append(firstName.toLowerCase());
		buff1.setCharAt(0, Character.toUpperCase(firstName.charAt(0)));
		firstName = buff1.toString();

		StringBuffer buff2 = new StringBuffer();
		buff2.append(Character.toUpperCase(middleName.charAt(0)));
		middleName = buff2.toString();

		StringBuffer buff3 = new StringBuffer();
		buff3.append(lastName.toLowerCase());
		buff3.setCharAt(0, Character.toUpperCase(lastName.charAt(0)));
		lastName = buff3.toString();

		StringBuffer buff4 = new StringBuffer();
		buff4.append(lastName);
		buff4.append(", ");
		buff4.append(firstName);
		buff4.append(" ");
		buff4.append(middleName);
		buff4.append(".");
		fullName = buff4.toString();

		return fullName;
	}

	public static boolean palindrome(String text) {
		// Check if text is a palindrome and return a true if it is and
		// false otherwise.
		
		StringBuffer tempStr = new StringBuffer(text);
		
		// Remove whitespace and commas
		for (int i = 0; i < tempStr.length(); i++) {
			if (tempStr.charAt(i) == ' ' || tempStr.charAt(i) == ',') {
				tempStr.deleteCharAt(i);
				i = 0; 	// Go back to the beginning after deleting a character
			}
		}
		
		text = tempStr.toString(); // Change original text to string
		
		tempStr = tempStr.reverse();
		String strReversed = tempStr.toString(); // Change reversed text to string
		
		if (strReversed.toLowerCase().equals(text.toLowerCase())) {
			return true;
		}
		else {
			return false;
		}
	}

}

public class Exercise2 {
	public static void tester() {
		// Test fullName with the following data
		// robert (first), james (middle), CLARK (last)
		// Test with data of your choice.
		
		String test = StringExercise.fullName("thomas", "vu", "NGUYEN");
		System.out.println("thomas vu NGUYEN: " + test);
		
		// Test palindrome() with the following data
		// A man, a plan, a canal, Panama
		// desserts
		// radar
		// Madam
		
		Boolean isPalindrome;
		
		isPalindrome = StringExercise.palindrome("A man, a plan, a canal, Panama");
		System.out.println("A man, a plan, a canal, Panama: " + isPalindrome);
		
		isPalindrome = StringExercise.palindrome("desserts");
		System.out.println("desserts: " + isPalindrome);
		
		isPalindrome = StringExercise.palindrome("radar");
		System.out.println("radar: " + isPalindrome);
		
		isPalindrome = StringExercise.palindrome("Madam");
		System.out.println("Madam: " + isPalindrome);
	}
}