package edu.scu.coen160.lab3;

/**
 * In this third exercise, we construct an interface from which both classes
 * `Box` and `Computer` need to implement.
 * 
 * In addition to the `Box` and `Driver` classes, we also have a driver class
 * called `Lab3_Q3` to test the interface methods
 * 
 * @author thomasnguyen
 *
 */

// This interface contains methods that must be implemented by `Box` and
// `Computer`
interface Lockable {
	public void lock(String key);

	public void unlock(String key);

	public void show();
}

class Box implements Lockable {
	private String boxno;
	private String key;
	boolean locked = false;

	// Constructor that instantiates a `key` based on `boxno`
	public Box(String boxno) {
		this.boxno = boxno;
		this.key = this.boxno;
	}

	// Locks box if keys match
	public void lock(String key) {
		if (key.equals(this.key)) {
			this.locked = true;
		}
	}

	// Unlocks box if keys match
	public void unlock(String key) {
		if (key.equals(this.key)) {
			this.locked = false;
		}
	}

	// Logs to console whether the box is locked or not
	public void show() {
		if (!this.locked) {
			System.out.println("Box:Showing Contents");
		} else
			System.out.println("Box:Locked");
	}
}

class Computer implements Lockable {
	private String password;
	private boolean locked = false;

	// Constructor for computer that instantiates a password as well
	public Computer(String pword) {
		setPassword(pword);
	}

	// Default constructor that leaves password as null
	public Computer() {
		password = null;
	}

	// Changes password of computer
	public void setPassword(String pword) {
		this.password = pword;
	}

	// Locks computer if password matches
	public void lock(String pword) {
		// Creates a password if it is currently null
		if (this.password == null) {
			this.password = pword;
			this.locked = true;
		} else if (this.password.equals(pword)) {
			this.locked = true;
		}
	}

	// Only unlocks computer if it is currently locked and you have the right password
	public void unlock(String pword) {
		if (this.locked == true) {
			if (this.password == pword) {
				this.locked = false;
			}
		}
	}

	// Logs to console whether the computer is locked or not
	public void show() {
		if (!locked) {
			System.out.println("Computer:ready");
		} else
			System.out.println("Computer:Locked");
	}
}

public class Lab3_Q3 {
	public static void q3() {
		Box box1 = new Box("1234");

		box1.lock("1234");
		box1.show();
		box1.unlock("1234");
		box1.show();

		Computer c1 = new Computer();
		c1.lock("coen160");
		c1.show();

		c1.unlock("coen160");
		c1.show();

		Lockable[] items = new Lockable[2];

		items[0] = box1;
		items[1] = c1;

		// We can run the code below because a box is a Lockable item
		items[0].show();
	}
}