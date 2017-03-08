abstract class Vehicle {
	protected int mpg;
	
	public Vehicle (int mpg) { this.mpg = mpg;}
	abstract public void move();
	public void show() { 
		System.out.println("MPG: "+mpg);
	}
}


class Car extends Vehicle{
	public Car (int mpg) { super(mpg);}
	public void move(){
		System.out.println("Car::move");
	}
	public void show() { 
		System.out.println("Car MPG: "+mpg);
	}
}


class PowerBoat extends Vehicle {
	public PowerBoat(int mpg) { super(mpg);}
	public void move(){
		System.out.println("Boat::move");
	}
	public void show() { 
		System.out.println("Boat MPG: "+mpg);
	}
}


//class VehicleNode {
//	Vehicle aVehicle; // Needs to be Private
//	VehicleNode next; // Needs to be Private
//	
//	public VehicleNode(Vehicle v) {aVehicle = v;next = null;}
//	public Vehicle getVehicle() { return aVehicle;}
//}


class MyLinkedList {
	private class VehicleNode {
		private Vehicle aVehicle;
		private VehicleNode next;
		
		public VehicleNode(Vehicle v) {aVehicle = v;next = null;}
		public Vehicle getVehicle() { return aVehicle;}
	}
	
	private VehicleNode first; // You need setters & getters
	private VehicleNode addHere;
	int cnt = 0;
	
	public void add(Vehicle v){		
		VehicleNode node = new VehicleNode(v);	
		if (first == null){			
			first = node;
			addHere = first;
			++cnt;
		}
		else{				
			addHere.next = node;
			addHere = addHere.next;
			++cnt;
		}		
	}
	public void showList(){
		VehicleNode current = first;
		System.out.println(cnt);
		while (current != null){
			
			current.getVehicle().show();
			current = current.next;			
		}
	}
}


public class LinkedListDemo {
	public static void main(String[] args) {
		MyLinkedList aList = new MyLinkedList();
		aList.add(new Car(60));
		aList.add(new PowerBoat(20));
		aList.add(new Car(70));
		aList.add(new PowerBoat(30));
		aList.add(new PowerBoat(10));
		aList.showList();
	}
}
