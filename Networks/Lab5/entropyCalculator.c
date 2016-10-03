// Thomas Nguyen
// Monday 2:15pm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


// Entropy Calculator

int main(int argc, char*argv[]) {
	if (argc != 2) {
		printf("Not the correct amount of arguments");
	}

	// Variables needed
	unsigned char buffer[4000000];
	int freq[256] = {0};
	int count = 0;
	double prob = 0;
	double entropy = 0;
	int i,j;
	
	// Read File
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		fprintf (stderr, "Unable to open file: (%s)\n", strerror(errno));
	}

	while ((i = read(fd, buffer, sizeof(buffer)))) {
		if (i == -1) {
			fprintf(stderr ,"Could not read file");
			close(fd);
			break;
		}

		// Reads through buffer and increments the corresponding
		// byte in the frequency array.
		for (j = 0; j < i; j++) {
			freq[buffer[j]]++;
			count++;
		}
	}

	close(fd);

	// Iterates through frequency array to calculate entropy
	for (i = 0; i < 256; i++) {
		if (freq[i]) {
			// Frequency Array -> Probability Distribution
			prob = (double)freq[i] / (double)count;
			// Shannon Entropy Formula
			entropy += (prob * (log2(1/prob)));	
		}
	}

	printf("Entropy: %f \n", entropy);
}
