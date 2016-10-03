// Thomas Nguyen
// Monday 2:15pm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		printf ("Incorrect number of inputs");
	}

	// Initialize Variables
	int i;

	// Takes in the number of bytes needed from command line
	long bytes = strtol(argv[1], NULL, 10);

	// Initializes array to be filled randomly with # of bytes
	char randTxt[bytes];
	
	for (i=0; i < bytes; i++) {
		// ASCII has 256 symbols
		// rand() will assign one to index of randTxt
		randTxt[i] = rand() % 256;
	}

	// Create or Open text file passed from input
	FILE *fp = fopen(argv[2],"w");

	// Put characters into file
	for (i=0; i < bytes; i++) {
		fputc(randTxt[i],fp);
	}

	fclose(fp);

}
