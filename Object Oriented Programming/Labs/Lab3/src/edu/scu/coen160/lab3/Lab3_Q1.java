package edu.scu.coen160.lab3;

/**
 * In this first exercise, we inherit the array class to implement the class for
 * a stack.
 * 
 * We also have a class called `Lab3_Q1` which is used as our driver to test the
 * `Stack` class
 * 
 * Answers to Questions: 1) If the stack issues a pop when no elements are
 * added, an exception will be thrown by the `Array` class and handled by the
 * `Stack` class. The result will be a returned value of -1
 * 
 * @author thomasnguyen
 *
 */

class Array {
	private int[] itemList;
	private int maxLength = 10;

	public Array(int length) {
		maxLength = length;
		itemList = new int[maxLength];
	}

	public Array() {
		itemList = new int[maxLength];
	}

	public void add(int index, int element) {
		if (index < maxLength && index >= 0) {
			itemList[index] = element;
		}
	}

	public int remove(int index) throws Exception {
		if (index < maxLength && index >= 0) {
			return itemList[index];
		} else {
			throw new Exception("Invalid index");
		}
	}

	public void show() {
		System.out.print("CurrentElements=");
		for (int i = 0; i < itemList.length; ++i)
			System.out.print(itemList[i] + " ");
		System.out.println();
	}
}

class Stack {
	// --------------- Implementation ---------------
	// Top of the stack -> back of the array
	// Bottom of the stack -> front of the array

	private int count = 0;
	private Array arr;

	// Constructor to instantiate with set length
	public Stack(int length) {
		arr = new Array(length);
	}

	// Adds element to end of the array and increments counter
	public void push(int value) {
		arr.add(count, value);
		this.count++;
	}

	// Removes element from the end of the array and returns value
	public int pop() {
		try {
			// If `arr.remove()` is given an invalid index, it will throw an
			// exception
			int value = arr.remove(count - 1);
			this.count--;
			return value;
		} catch (Exception e) {
			return -1;
		}
	}

	// Pops all items off the stack and prints
	public void showStack() {
		for (int i = this.count; i > 0; i--) {
			int value = this.pop();
			System.out.println(value);
		}
	}
}

public class Lab3_Q1 {
	public static void q1() {
		Stack myStack = new Stack(30);

		myStack.push(10);
		myStack.push(20);
		myStack.push(30);
		myStack.push(40);

		System.out.println("pop()=" + myStack.pop());

		myStack.showStack();
	}
}