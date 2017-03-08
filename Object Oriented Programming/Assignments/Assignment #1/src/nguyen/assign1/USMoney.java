package nguyen.assign1;

/**
 * This class `USMoney` allows you to instantiate & add to an object that
 * represents an amount of US currency.
 * 
 * @author thomasnguyen
 *
 */

public class USMoney {
	private int dollars;
	private int cents;

	/**
	 * Default constructor
	 */
	public USMoney() {
		setDollars(0);
		setCents(0);
	}

	/**
	 * Constructor to instantiate USMoney with certain dollar and cent amount
	 * 
	 * @param dollars
	 *            integer value to represent number of dollars
	 * @param cents
	 *            integer value to represent number of cents
	 */
	public USMoney(int dollars, int cents) {
		// We will restrict the user to only positive values for USMoney
		if (cents < 0 || dollars < 0) {
			System.out.println("You cannot enter a negative value for dollars or cents");
		}

		setDollars(dollars);
		setCents(cents);
		
		this.validAmount();
	}

	public int getDollars() {
		return dollars;
	}

	public void setDollars(int dollars) {
		this.dollars = dollars;
		this.validAmount();
	}

	public int getCents() {
		return cents;
	}

	public void setCents(int cents) {
		this.cents = cents;
		this.validAmount();
	}

	/**
	 * Adds a specific amount of dollars and cents to the current USMoney object
	 * that this method is being called from
	 * 
	 * @param dollars
	 *            integer value of dollars to be added
	 * @param cents
	 *            integer value of cents to be added
	 */
	public void addTo(int dollars, int cents) {
		if (cents < 0 || dollars < 0) {
			System.out.println("You cannot enter a negative value for dollars or cents");
		}

		this.dollars += dollars;
		this.cents += cents;

		this.validAmount();
	}

	/**
	 * Adds together the current USMoney object this method is being called
	 * from, and another USMoney object that is being passed in as an argument
	 * 
	 * @param money
	 *            a USMoney object containing its dollars and cents values
	 * @return USMoney a new USMoney object with cents & dollars added together
	 */
	public USMoney add(USMoney money) {
		int sumDollars;
		int sumCents;

		sumDollars = this.dollars + money.dollars;
		sumCents = this.cents + money.cents;

		USMoney sum = new USMoney(sumDollars, sumCents);

		return sum;
	}

	/**
	 * Method is used when calling `System.out.println()` on an object of type
	 * USMoney
	 */
	public String toString() {
		String output;

		StringBuffer buff = new StringBuffer();
		buff.append("$");
		buff.append(this.dollars);
		buff.append(".");
		buff.append(this.cents);

		output = buff.toString();

		return output;
	}

	/**
	 * Helper function that readjusts dollars and cents value to make sure we
	 * don't have more than 100 cents
	 */
	private void validAmount() {
		if (this.cents > 99) {
			while (this.cents > 99) {
				this.cents -= 100;
				this.dollars += 1;
			}
		}
	}
}
