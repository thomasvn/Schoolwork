#include <iostream>
using namespace std;

int main() {
    int i, j, k;

    // Prompt user for the value j
    cout << "Enter a value for j: ";
    cin >> j;

    for (k = ((j + 13) / 27); k <= 10; k++) {
        i = 3 * k - 1;
    }

    cout << "i: " << i << endl;
}
