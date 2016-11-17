#include <iostream>
using namespace std;

int main() {
    // Initialize example 2D matrix
    int n = 5;
    int x[5][5] = {
        {0,0,0,1,0},
        {0,0,1,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,1},
    };

    for (int i = 0; i <= n; i++) {
        // Flag to see if entire row is zero
        int flag = 0;
        for (int j = 0; j <= n; j++) {
            if (x[i][j] != 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cout << "First all-zero row is: " << i+1 << endl;
        }
    }
}
