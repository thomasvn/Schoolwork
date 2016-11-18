#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class stack_dynamic {
public:
    void stack_dynamic_array();
};

void stack_dynamic::stack_dynamic_array() {
    int arr4[100][100], arr5[100][100], arr6[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr4[i][j] = rand() % 100;
            arr5[i][j] = rand() % 100;
        }
    }

    int stack_dynamic_result[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            stack_dynamic_result[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                stack_dynamic_result[i][j] = stack_dynamic_result[i][j] + arr4[i][k] * arr5[k][j];
            }
        }
    }
}

int main() {
    time_t start;
    double duration;

    static int arr1[100][100], arr2[100][100], arr3[100][100];
    stack_dynamic x;


    // Stack-Dynamic Matrix Operations
	start = clock();
    x.stack_dynamic_array();
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Stack-Dynamic Matrix Operations: %lfs\n", duration);

	// Static Matrix Operations
	start = clock();

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }
    }

    int static_result[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            static_result[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                static_result[i][j] = static_result[i][j] + arr1[i][k] * arr2[k][j];
            }
        }
    }

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	printf("Static Matrix Operations: %lfs\n", duration);
}
