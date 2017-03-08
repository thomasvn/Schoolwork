package edu.scu.coen160.lab4;

import java.util.Scanner;

/**
 * `MissedFlight` can be instantiated as an Exception object which throws an
 * exception if the flight does not start with 2 or 3 letters
 * 
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class MissedFlight extends Exception { // For exercise 5
	private String flight;

	/**
	 * Constructor of `MissedFlight` object which instantiates flight name as
	 * long as it does starts with 2 or 3 letters
	 * 
	 * @param flight
	 *            String of flight name
	 * @throws Exception
	 *             Default Exception
	 */
	public MissedFlight(String flight) throws Exception {
		int letter_count = 0;

		// Checks to make sure flight starts with 2 or 3 letters
		for (int i = 0; i < 3; i++) {
			if (Character.isDigit(flight.charAt(i)) && letter_count < 2) {
				System.out.println(flight.charAt(i));
				throw new Exception();
			}
			letter_count++;
		}

		// Initialize data member `flight` if we do not throw exception
		this.flight = flight;
	}

	public String toString() {
		return "Missed flight: " + flight;
	}
}

/**
 * `CanceledFlight` can be instantiated as an Exception object which throws an
 * exception if the flight does not start with 2 or 3 letters
 * 
 * @author ThomasNguyen
 */
@SuppressWarnings("serial")
class CanceledFlight extends Exception { // For exercise 5
	private String flight;

	/**
	 * Constructor of `MissedFlight` object which instantiates flight name as
	 * long as it does starts with 2 or 3 letters
	 * 
	 * @param flight
	 *            String of flight name
	 * @throws Exception
	 *             Default Exception
	 */
	public CanceledFlight(String flight) throws Exception {
		int letter_count = 0;

		// Checks to make sure flight starts with 2 or 3 letters
		for (int i = 0; i < 3; i++) {
			if (Character.isDigit(flight.charAt(i)) && letter_count < 2) {
				throw new Exception();
			}
			letter_count++;
		}

		// Initialize data member `flight` if we do not throw exception
		this.flight = flight;
	}

	public String toString() {
		return "Canceled flight: " + flight;
	}
}

/**
 * This class can be considered the driver with multiple static methods (used
 * for exercises) as well as a main.
 * 
 * @author ThomasNguyen
 */
public class Lab4 {
	/**
	 * This first exercise allows us to practice catching a runtime exception
	 */
	public static void exer1() {
		int denominator, numerator;
		numerator = 4;
		denominator = 0;

		try {
			System.out.println("Result: " + numerator / denominator);
		} catch (Exception e) {
			System.err.println("Error: " + e + "\n");
		}

		System.out.println("exer1 - end.");
	}

	/**
	 * In this exercise similar to `exer1()`, we catch the runtime exception in
	 * the main driver as opposed to this specific method
	 */
	public static void exer1_2() {
		int denominator, numerator;
		numerator = 4;
		denominator = 0;

		System.out.println("Result: " + numerator / denominator);
		System.out.println("exer1_2 - end.");
	}

	/**
	 * This exercise catches an error thrown when reading an integer from the
	 * user
	 */
	public static void exer2() {
		int num = 0;

		System.out.print("Enter an integer: ");
		Scanner scanner = new Scanner(System.in);

		try {
			// Squaring the number input
			num = scanner.nextInt();
			System.out.println("The square of " + num + " is " + num * num);
		} catch (java.util.InputMismatchException e) {
			// Execute if there is a mismatch of types inputed
			System.err.println("Error: " + e + "\n");
		} catch (Exception e) {
			System.err.println("Error: " + e + "\n");
		}

		System.out.println("exer2 - end.");
		scanner.close();
	}

	/**
	 * This exercise is similar to `exer2()`, but this version recursively calls
	 * itself to make sure we do not return from the method without entering in
	 * a proper input
	 */
	public static void exer2_2() {
		int num = 0;

		System.out.print("Enter an integer: ");
		Scanner scanner = new Scanner(System.in);

		try {
			// Squaring the number input
			num = scanner.nextInt();
			System.out.println("The square of " + num + " is " + num * num);
			System.out.println("exer2 - end.");
		} catch (java.util.InputMismatchException e) {
			// Execute if there is a mismatch of types inputed
			System.out.println("You did not enter an integer. Try again.");
			exer2_2();
		} catch (Exception e) {
			System.err.println("Error: " + e + "\n");
		}

		scanner.close();
	}

	/**
	 * This method utilizes the Exception objects we created for `MissedFlight`
	 * and `CanceledFlight` by instantiating both objects with different
	 * statuses and flight numbers
	 * 
	 * @param status
	 *            Choose between instantiating `MissedFlight` or
	 *            `CanceledFlight`
	 * @param flight
	 *            A string which is the name of the flight
	 * @throws Exception
	 *             Throws the respective Exception object back to main
	 */
	public static void exer5(int status, String flight) throws Exception {
		try {
			switch (status) {
			case 1:
				throw new MissedFlight(flight);
			case 2:
				throw new CanceledFlight(flight);
			default:
				System.out.println("Arriving as planned");
			}
		} catch (MissedFlight e) {
			System.out.println(e);
		} catch (CanceledFlight e) {
			System.out.println(e);
		} finally {
			// The finally block will always run after a `try` or `catch` block
			System.out.println("Appointment moved to 11th March");
		}
		System.out.println("exer5 - done\n");
	}

	/**
	 * This is our main driver that calls all the static methods from the `Lab4`
	 * class
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		// ---------------- Question 1 ----------------
		// Lab4.exer1();

		// ---------------- Question 2 ----------------
		// Lab4.exer2();

		// ---------------- Question 3 ----------------
		// try {
		// Lab4.exer1_2();
		// } catch (Exception e) {
		// System.err.println("Error: " + e + "\n");
		// }

		// ---------------- Question 4 ----------------
		// Lab4.exer2_2();

		// ---------------- Question 5 ----------------
		// try {
		// Lab4.exer5(1, "AA123");
		// Lab4.exer5(3, "AA123");
		// Lab4.exer5(2, "12345");
		// } catch (Exception e) {
		// System.err.println("Error: " + e + "\n");
		// }

	}
}