package nguyen.assign1;

/**
 * This class `MyUtil` contains two static methods that perform different tasks
 * as detailed below. There is also a driver method included to test the two
 * static methods
 * 
 * @author thomasnguyen
 *
 */

public class MyUtil {

	/**
	 * This method takes an array as an input and returns a String that is
	 * formatted nicely with the contents of the array
	 * 
	 * @param array
	 *            an array of integer values
	 * @return a String with the contents of the array formatted well
	 */
	public static String displayArray(int[] array) {
		String output;
		StringBuffer buff = new StringBuffer();

		buff.append("{ ");

		// Place integer contents of array into string buffer
		for (int i = 0; i < array.length; i++) {
			if (i != 0) {
				buff.append(", ");
			}
			buff.append(array[i]);
		}

		buff.append(" }");

		output = buff.toString();

		return output;
	}

	/**
	 * This method takes an integer value and prints the reverse value of this
	 * integer
	 * 
	 * @param aNumber
	 *            an integer
	 */
	public static void reverseANumber(int aNumber) {
		int power = 0;

		while (Math.pow(10, power) < aNumber) {
			// Divide number by 10 to the power of an exponent
			int place_value = (int) (aNumber / Math.pow(10, power));

			// Place_value mod 10 to get the value that is currently in the ones
			// digit
			place_value = place_value % 10;

			System.out.print(place_value);
			power += 1;
		}

	}

	/**
	 * Main method created to test the two static methods of `MyUtil`
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		String output;
		int arr[] = { 1, 2, 3, 4, 5 };

		output = MyUtil.displayArray(arr);
		System.out.println(output);

		MyUtil.reverseANumber(1234);
	}
}
