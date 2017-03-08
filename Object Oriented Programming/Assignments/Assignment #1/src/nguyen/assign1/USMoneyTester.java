package nguyen.assign1;

/**
 * This class `USMoneyTester` was created to test all methods created in the
 * class USMoney
 * 
 * @author thomasnguyen
 *
 */

public class USMoneyTester {
	public static void main(String[] args) {
		USMoney amt1 = new USMoney();
		System.out.println(amt1); // $0.0
		amt1.setCents(250);
		System.out.println(amt1); // $2.50
		amt1.setDollars(10);
		System.out.println(amt1); // $10.50
		System.out.println(amt1.getCents()); // 50
		USMoney amt2 = amt1.add(new USMoney(2, 90));
		System.out.println(amt1); // $10.50
		System.out.println(amt2); // $13.40
		amt2.addTo(amt1.getDollars(), amt1.getCents());
		System.out.println(amt2); // $23.90
	}
}
