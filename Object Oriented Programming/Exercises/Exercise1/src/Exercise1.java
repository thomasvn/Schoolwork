abstract class Tool {
	abstract double getPrice();
	abstract void toDo();
}

class Hammer extends Tool{
	private double price;

	public double getPrice() { return price;}
	public void toDo() {System.out.println("To drive a nail."); }
}

class Wrench extends Tool {
	private double price;
	
	public double getPrice() { return price;}
	public void toDo() {System.out.println("To provide grip."); }
}

class Toolbox {
	private double price;
	Hammer hammer = new Hammer();
	Wrench wrench = new Wrench();
	
	public Toolbox() {
		price = 0;
	}
	public Toolbox (int hammerPrice, int wrenchPrice) {
		price = hammerPrice + wrenchPrice;
	}
	public Toolbox (Hammer hammer, Wrench wrench) {
		this.hammer = hammer;
		this.wrench = wrench;
		price = this.hammer.getPrice() + this.wrench.getPrice();
	}
	
	// Returns the total price of the contained tools;
	public double getPrice() {
		return price;
	}

}

public class Exercise1 {
	public static void main(String[] args) {
		// Create a ToolBox
		Toolbox toolbox = new Toolbox();
		System.out.println(toolbox.getPrice());

		Hammer h1 = new Hammer();
		Tool t1 = h1;
		t1 = new Wrench();		
		// h1 = t1; Hammer cannot be a generic tool
	}
}
