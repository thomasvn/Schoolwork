/*
 *	Thomas Nguyen and Darence Lim
 *	Tuesday 2:15 Lab
 *	Lab6
 *
*/


#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Player.h"

using namespace std;

// --------------- CPU Class ----------------
class cpu:virtual public Player {
private:
	int guess;
public:
	cpu() { }
	~cpu() { }
	int getGuess() { return guess; }
	void lastWasTooHigh(bool tooHigh);
	void opponentsGuess(int guess, bool tooHigh);
	void reset() { guess = -1; }

	void setGuess(int source) { guess = source; }
};

// -------------- User Class --------------
class user:virtual public Player {
private:
	int guess;
public:
	user() { }
	~user() { }
	int getGuess() { return guess; }
	void lastWasTooHigh(bool tooHigh);
	void opponentsGuess(int guess, bool tooHigh);
	void reset() { guess = -1; }

	void setGuess(int source) { guess = source; }
};

// -------------- CPU Member Functions -----------------
void cpu::lastWasTooHigh(bool tooHigh) {
	if (tooHigh) {
		cout << "Your(cpu) guess was too high" << endl;
	}
	else {
		cout << "Your(cpu) guess was too low" << endl;
	}
}

void cpu::opponentsGuess(int guess, bool tooHigh) {
	if (tooHigh) {
		cout << "The user's guess: " << guess;
		cout << " was too high" << endl;
	}
	else {
		cout << "The user's guess: " << guess;
		cout << " was too low" << endl;
	}
}

// -------------- User member functions ----------------
void user::lastWasTooHigh(bool tooHigh) {
	if (tooHigh) {
		cout << "Your(user) guess was too high" << endl;
	}
	else {
		cout << "Your(user) guess was too low" << endl;
	}
}

void user::opponentsGuess(int guess, bool tooHigh) {
	if (tooHigh) {
		cout << "The cpu's guess: " << guess;
		cout << " was too high" << endl;
	}
	else {
		cout << "The cpu's guess: " << guess;
		cout << " was too low" << endl;
	}
}


int main() {
	cpu comp;
	user you;
	
	int solution;
	int cpuGuess, userGuess;
	bool tooHigh;
	
	int cpuCounter = 0;
	int userCounter = 0;
	
	int lowBound = 0;
	int highBound = 99;

	char x;
	
	srand(time(NULL));
	solution = rand()%100;
	
	while (1) {
	while (1) {
		// --------------- Computer --------------
		if (cpuCounter != 0) {
			comp.opponentsGuess(userGuess, tooHigh);
		}

		// Computer guesses number
		if (cpuCounter == 0) {
			srand(time(NULL));
			cpuGuess = 50;
		}
		else {
			srand(time(NULL));
			cpuGuess = ((highBound + lowBound)/2);
		}
		comp.setGuess(cpuGuess);
		cpuCounter++;
		if (cpuGuess == solution) {
			cout << "Congratulations, you beat your creator!" << endl;
			cout << "Number of guesses: " << cpuCounter << endl;
			comp.reset();
			highBound = 99;
			lowBound = 0;
			break;
		}

		// Computer is too high or not
		if (cpuGuess > solution) {
			tooHigh = true;
			highBound = cpuGuess;
		}
		else {
			tooHigh = false;
			lowBound = cpuGuess;
		}
		comp.lastWasTooHigh (tooHigh);
		


		// --------------- User ---------------
		you.opponentsGuess(cpuGuess, tooHigh);
		
		// User guesses number
		cout << "Please guess a number between 0 to 99:  ";
		cin >> userGuess;
		you.setGuess(userGuess);
		userCounter++;
		if (userGuess == solution) {
			cout << "Congratulations, you beat the computer!" << endl;
			cout << "Number of guesses: " << userCounter << endl;
			you.reset();
			highBound = 99;
			lowBound = 0;
			break;
		}
		
		// User is too high or not
		if (userGuess > solution) {
			tooHigh = true;
			highBound = userGuess;
		}
		else  {
			tooHigh = false;
			lowBound = userGuess;
		}
		you.lastWasTooHigh (tooHigh);

	}

	cout << "Do you want to play again? (Y/N)" << endl;
	cin >> x;
	if ('Y' == x) {
		cout << "Let's play again!" << endl;
	}
	else {
		cout << "Thanks for playing!" << endl;
		break;
	}
		
	}

	return 0;
}




