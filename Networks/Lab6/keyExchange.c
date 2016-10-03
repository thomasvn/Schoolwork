// Thomas Nguyen
// Monday 2:15 - 5:00pm

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Diffie-Hellman Key Exchange Algorithm

/*
 * 	NOTE
 *	The pow() function used in this program takes in doubles
 *	and outputs doubles. As a result when using large numbers
 *	that exceed the limits of doubles, the pow function will
 *	overflow and the program will seg fault as a result.
*/


// Function to check if number is prime
// Returns (1) if prime and (0) if not prime.
int isPrime(long long int num) {
	int i;
	if (num <= 1) {
		return 0;
	}
	if (num % 2 == 0) {
		return 0;
	}
	for (i = 2; i < num / 2; i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}


int main() {
	
	// Variables
	long long int prime;
	long long int root;
	long long int alicePrivKey;
	long long int bobPrivKey;
	long long int alicePubKey;
	long long int bobPubKey;
	long long int aliceCalculated;
	long long int bobCalculated;
	
	// Prompt User for a Prime Number and store input in p
	printf("Please enter a prime number: \n");
	scanf("%lld", &prime);
	if (isPrime(prime) == 0) {
		printf("Sorry... that's not a prime number\n");
		return 0;
	}
		
	// Prompt user for a primitive root of p and store the input in r
	// Error checking for primitive root is not available.
	printf("Please enter a primitive root of the prime number: \n");
	scanf("%lld", &root);	

	// Prompt user for Alice's private key and store the input in a
	printf ("Please enter Alice's private key: \n");
	scanf("%lld", &alicePrivKey);
		
	// Prompt user for Bob's private key and store the input in b
	printf ("Please enter Bob's Private Key: \n");
	scanf("%lld", &bobPrivKey);

	// Calculate Alice's public key (x = r^a mod p)
	alicePubKey = (long long int)pow(root, alicePrivKey) % prime;		 

	// Calculate Bob's public key (y = r^b mod p)
	bobPubKey = (long long int)pow(root, bobPrivKey) % prime;
	
	// Assume public values x and y are exchanged
	
	// Calculate Alice's shared private key (k = y^a mod p)
	aliceCalculated = (long long int)pow(bobPubKey, alicePrivKey) % prime;
	
	// Calculate Bob's shared private key (k = x^b mod p)
	bobCalculated = (long long int)pow(alicePubKey, bobPrivKey) % prime;	

	// Are both values of k equal?
	printf ("\nAlice's Calculated Value: %lld \n", aliceCalculated);
	printf ("Bob's Calculated Value: %lld \n\n", bobCalculated);

	return 0;
}




