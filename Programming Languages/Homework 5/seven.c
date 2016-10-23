/*
 * Write a C program that does a large number of references to elements of
 * two-dimensioned arrays, using only subscripting. Write a second program
 * that does the same operations but uses pointers and pointer arithmetic for
 * the storage-mapping function to do the array references. Compare the time
 * efficiency of the two programs. Which of the two programs is likely to be
 * more reliable? Why?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10000
#define COLS 10000

int array[ROWS][COLS];

void subscripts() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            array[i][j] = 1;
        }
    }
}

void pointers() {
    int i, j;
    int *ptr = (int*)array;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            *(ptr + (i * ROWS) + j) = 1;
        }
    }
}

int main() {
    time_t start, end;
    double duration;

    // Timing subscript function
	start = clock();
	subscripts();
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	printf("Subscripts Function: %lfs\n",duration);

    // Timing pointers function
	start = clock();
	pointers();
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	printf("Pointers Function: %lfs\n",duration);

	return 0;
}
