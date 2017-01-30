package edu.scu.coen160.lab2;

import java.util.Scanner;

/**
 * Exercise1.java
 * 
 * This exercise includes a class that checks "things". The "thing" we were 
 * checking was whether or not an integer entered was a leap year.
 * 
 * We also created two testers; one of which utilized hard-coded input, while
 * the other took user input.
 * 
 * @author thomasnguyen
 *
 */

class CheckThings {
	public boolean isItALeapYear(int year) {
		// This method should check if the parameter year is a leap year and
		// return a true. Otherwise a false.

		// A leap year is a year that is divisible by 4 and not by hundred
		if ((year % 4 == 0) && (year % 100 != 0)) {
			return true;
		} 
		// A leap year is also divisible by 400.
		else if (year % 400 == 0) {
			return true;
		} 
		else {
			return false;
		}
	}
}

public class Exercise1 {
	public static void tester1() {
		CheckThings tester = new CheckThings();
		
		System.out.println(tester.isItALeapYear(1716));
		System.out.println(tester.isItALeapYear(1989));
		System.out.println(tester.isItALeapYear(1992));
		System.out.println(tester.isItALeapYear(2000));
		System.out.println(tester.isItALeapYear(2010));
		System.out.println(tester.isItALeapYear(2012));
		
		System.out.println("The year 2000s");
		System.out.println(tester.isItALeapYear(2000));
		System.out.println(tester.isItALeapYear(2001));
		System.out.println(tester.isItALeapYear(2002));
		System.out.println(tester.isItALeapYear(2003));
		System.out.println(tester.isItALeapYear(2004));
		System.out.println(tester.isItALeapYear(2005));
		System.out.println(tester.isItALeapYear(2006));
		System.out.println(tester.isItALeapYear(2007));
		System.out.println(tester.isItALeapYear(2008));
		System.out.println(tester.isItALeapYear(2009));
		
//		System.out.println(CheckThings.isItALeapYear(1716));
//		System.out.println(CheckThings.isItALeapYear(1989));
//		System.out.println(CheckThings.isItALeapYear(1992));
//		System.out.println(CheckThings.isItALeapYear(2000));
//		System.out.println(CheckThings.isItALeapYear(2010));
//		System.out.println(CheckThings.isItALeapYear(2012));
//		
//		System.out.println("The year 2000s");
//		System.out.println(CheckThings.isItALeapYear(2000));
//		System.out.println(CheckThings.isItALeapYear(2001));
//		System.out.println(CheckThings.isItALeapYear(2002));
//		System.out.println(CheckThings.isItALeapYear(2003));
//		System.out.println(CheckThings.isItALeapYear(2004));
//		System.out.println(CheckThings.isItALeapYear(2005));
//		System.out.println(CheckThings.isItALeapYear(2006));
//		System.out.println(CheckThings.isItALeapYear(2007));
//		System.out.println(CheckThings.isItALeapYear(2008));
//		System.out.println(CheckThings.isItALeapYear(2009));
	}
	
	public static void tester2() {
		CheckThings tester = new CheckThings();
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter in a year to check whether or not it is a leap year");
		int year = in.nextInt();
		
		System.out.println(year + ": " + tester.isItALeapYear(year));
//		System.out.println(year + ": " + CheckThings.isItALeapYear(year));
	}
}
