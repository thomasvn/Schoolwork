#include <iostream>
#include <time.h>
using namespace std;

void passByValue(int arr[1000000]) {
    return;
}

void passByReference(int* p) {
    return;
}

int main() {
    int arr[1000000];
    time_t start;
	double duration;

    // Pass By Value Operations
	start = clock();
    for (int i = 0; i < 1000000000; i++) {
        passByValue(arr);
    }
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Pass By Value Operations: %lfs\n", duration);

	// Pass By Reference Operations
	start = clock();
    for (int i = 0; i < 1000000000; i++) {
        passByReference(arr);
    }
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Pass By Reference Operations: %lfs\n", duration);
}
