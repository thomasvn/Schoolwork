class four{
	public static int fun(int k) {
		k += 10;
		return k;
	}	
	
	public static void main(String[] args) {
		int i = 10, j = 10, sum1, sum2;
		sum1 = (i/2) + fun(i);
		sum2 = fun(j) + (j/2);
		System.out.println("sum1: " + sum1 + "\nsum2: " + sum2);
	}
}
