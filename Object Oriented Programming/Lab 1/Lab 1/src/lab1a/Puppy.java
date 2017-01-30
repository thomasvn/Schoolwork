package lab1a;

/**
 * The Puppy class contains constructors to instantiate instances of Puppy with
 * the option of setting its name and age.
 * 
 * This class also includes setters and getters to interface with the private
 * member variables
 * 
 * Answers to Questions 
 * 1a) Yes we see the name FIDO
 * 
 * @author thomasnguyen
 *
 */

public class Puppy {
	// ---------- Private Member Variables ---------- //
	private String name;
	private int age;

	// --------------- CONSTRUCTORS --------------- //
	public Puppy() {
		name = "Name not given yet";
		age = 0;
	}

	public Puppy(String name, int age) {
		this.name = name;
		this.age = age;
	}

	// --------------- GETTERS --------------- //
	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	// --------------- SETTERS --------------- //
	public void setName(String name) {
		this.name = name;
	}

	public void setAge(int age) {
		this.age = age;
	}
}
