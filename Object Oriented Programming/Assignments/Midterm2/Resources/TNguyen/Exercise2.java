package midterm2;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import javax.swing.*;

/**
 * This class includes information about a club member. When instantiating the
 * object, you must provide the first name, last name, and age. This class also
 * provides getters for the data members
 * 
 * @author thomasnguyen
 *
 */
class ClubMember {
	private String firstName;
	private String lastName;
	private int age;

	ClubMember(String firstName, String lastName, int age) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.age = age;
	}

	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public int getAge() {
		return age;
	}
}

/**
 * This class includes a list of Club Members. Methods are also provided to add
 * members to the club and obtain the list of members in the club.
 * 
 * @author thomasnguyen
 *
 */
class Club {
	private ArrayList<ClubMember> memberList;

	public Club() {
		memberList = new ArrayList<ClubMember>();
	}

	public void addMember(ClubMember member) {
		memberList.add(member);
		System.out.println("You just added " + member.getFirstName());
	}

	public ArrayList<ClubMember> getMemberList() {
		return memberList;
	}
}

/**
 * The `ClubRoster` class offers a GUI to the `Club` and `ClubMember` classes.
 * Using this GUI, you can view the list of club members in the club sorted by
 * name or age.
 * 
 * @author thomasnguyen
 *
 */
@SuppressWarnings("serial")
class ClubRoster extends JFrame {
	private JButton showByLastName, showByAge;
	private JLabel results;
	private JPanel panel;
	private String resultsBuffer = "<html>Results:<br><html>";

	ClubRoster(Club club) {
		super("Club");

		// Set up the GUI
		setSize(400, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container container = getContentPane();
		container.setLayout(new BorderLayout());
		results = new JLabel(resultsBuffer);
		container.add(results, BorderLayout.CENTER);

		// Create "Show By Last Name" button
		showByLastName = new JButton(new AbstractAction("Show By Last Name") {
			// Message this method when button is clicked
			@Override
			public void actionPerformed(ActionEvent e) {
				sortClubMembersByLastName(club);

				// Remove current `results` label and place the new one in
				container.remove(results);
				results = new JLabel(resultsBuffer);
				container.add(results, BorderLayout.CENTER);
				revalidate();
			}
		});

		// Create "Show By Age" button
		showByAge = new JButton(new AbstractAction("Show By Age") {
			// Message this method when button is clicked
			@Override
			public void actionPerformed(ActionEvent e) {
				sortClubMembersByAge(club);

				// Remove current `results` label and place the new one in
				container.remove(results);
				results = new JLabel(resultsBuffer);
				container.add(results, BorderLayout.CENTER);
				revalidate();
			}
		});

		// Add buttons to top of the GUI
		panel = new JPanel();
		panel.add(showByLastName);
		panel.add(showByAge);
		container.add(panel, BorderLayout.NORTH);

		setLocationRelativeTo(null);
		setVisible(true);
	}

	/**
	 * Method used to sort the club members by last name
	 * 
	 * @param club
	 */
	private void sortClubMembersByLastName(Club club) {
		Collections.sort(club.getMemberList(), new Comparator<ClubMember>() {
			@Override
			public int compare(ClubMember person1, ClubMember person2) {
				return person1.getLastName().compareTo(person2.getLastName());
			}
		});

		organizeResults(club);
	}

	/**
	 * Method used to sort the club members by age
	 * 
	 * @param club
	 */
	private void sortClubMembersByAge(Club club) {
		Collections.sort(club.getMemberList(), new Comparator<ClubMember>() {
			@Override
			public int compare(ClubMember person1, ClubMember person2) {
				if (person1.getAge() == person2.getAge()) {
					return 0;
				} else if (person1.getAge() < person2.getAge()) {
					return -1;
				} else {
					return 1;
				}
			}
		});

		organizeResults(club);
	}

	/**
	 * Arranges the items in the list of members to be properly placed in a
	 * label
	 * 
	 * @param club
	 */
	private void organizeResults(Club club) {
		resultsBuffer = "<html>Results:<br>";
		for (ClubMember person : club.getMemberList()) {
			resultsBuffer += person.getLastName() + ", " + person.getFirstName() + "  " + person.getAge() + "<br>";
		}
		resultsBuffer += "<html>";
	}
}

/**
 * The driver method which creates a `Club` and adds many `ClubMember`s. We can
 * then view these club members on our `ClubRoster` GUI
 * 
 * @author thomasnguyen
 *
 */
public class Exercise2 {
	public static void main(String[] args) {
		Club club = new Club();
		club.addMember(new ClubMember("Thomas", "Nguyen", 20));
		club.addMember(new ClubMember("Drew", "Fajardo", 24));
		club.addMember(new ClubMember("Ivy", "Fernandes", 28));
		club.addMember(new ClubMember("Tiffany", "Vien", 6));
		club.addMember(new ClubMember("Patrick", "Wu", 68));
		club.addMember(new ClubMember("Michael", "Ney", 18));
		club.addMember(new ClubMember("Olivia", "Hsieh", 16));
		club.addMember(new ClubMember("David", "Levitsky", 49));
		club.addMember(new ClubMember("Ryan", "O'Leary", 35));
		club.addMember(new ClubMember("Shivajee", "Samdarshi", 52));

		new ClubRoster(club);
	}
}