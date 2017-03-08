package edu.scu.coen160.lab3;

/**
 * In this second exercise, we have a `BuildingManager` class overwatching a
 * number of his `Assets` which are specifically `PowerUsers`.
 * 
 * The objective of this exercise was to fix the relationships among classes so
 * that the BuildingManager would be able to properly shut down all PowerUsers
 * 
 * @author thomasnguyen
 *
 */

// All PowerUsers are the BuildingManager's Assets
class PowerUser extends Asset {
}

class EmergencyLight extends PowerUser {
}

class PersonalComputer extends PowerUser {
}

class TV extends PowerUser {
}

class Asset {
	// Log to the console that an Asset is being powered down
	public void powerDown() {
		System.out.println("Powering down");
	}
}

class BuildingManager {
	Asset things[] = new Asset[24];
	int numItems = 0;

	// Turns off appliances in his Asset array `things[]` if they are still on
	// or "instantiated"
	public void powerDownAtNight() {
		for (int i = 0; i < things.length; i++)
			if (things[i] != null)
				things[i].powerDown();
	}

	// Adds an Asset to the building
	public void add(Asset thing) {
		things[numItems] = thing;
		numItems++;
	}
}

public class Lab3_Q2 {
	public static void q2() {
		BuildingManager b1 = new BuildingManager();

		b1.add(new EmergencyLight());
		b1.add(new PersonalComputer());
		b1.add(new TV());
		b1.powerDownAtNight();
	}
}