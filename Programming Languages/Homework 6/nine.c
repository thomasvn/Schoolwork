#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void intOperations() {
	int i = 0;
	int x = 1;
	for (i = 0; i < 100000; i++) {
		x *= (i);
	}	
}

void floatOperations() {
	int i = 0;
	float x = 1.1;
	for (i = 0; i < 100000; i++) {
		x *= (i + 1.1);
	}
}

int main(int argc, char *argv[]) {
	time_t start;
	double duration;
	
	// Integer Operations
	start = clock();
	intOperations();
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Integer Operations: %lfs\n", duration);
	
	// Float Operations
	start = clock();
	floatOperations();
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Float Operations: %lfs\n", duration);
}