package edu.scu.coen160.lab3;

/**
 * In this exercise, we'll be practicing using the `System.arraycopy()`
 * function. Because this was placed in a static method, it will be called
 * directly from main.java
 * 
 * @author thomasnguyen
 *
 */

public class Lab3_Q4 {
	public static void q4() {
		// Example
		char[] fromArray = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
		char[] toArray = new char[10];

		System.arraycopy(fromArray, 2, toArray, 0, 10);
		System.out.println("Array unchanged = " + new String(toArray) + "\n");

		
		// Exercise 1
		// ************************************************************************
		char[] arr = new char[5];
		arr[0] = 'A';
		arr[1] = 'B';
		arr[2] = 'C';
		arr[3] = 'D';
		System.out.println("Array unchanged = " + new String(arr));

		// Inserts 'X' in the middle of array, using arraycopy().
		System.arraycopy(arr, 2, arr, 3, 2);
		arr[3] = 'X';

		System.out.println("Array   changed = " + new String(arr));

		
		// Exercise 2
		// ************************************************************************
		char[] courseName = { 'C', 'O', 'E', 'N', '2', '1', '6', '0' };
		System.out.println("Array unchanged = " + new String(courseName));

		// Removes '2' from courseName, using arraycopy().
		System.arraycopy(courseName, 5, courseName, 4, 3);
		courseName[7] = ' ';
		System.out.println("Array   changed = " + new String(courseName));
	}
}