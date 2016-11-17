#include <iostream>
using namespace std;

int main() {
    int i, j, k;

    // Prompt user for variable k
    cout << "Enter an integer between 1 and 8: ";
    cin >> k;

    switch(k) {
        case (1): case (2):
            j = 2 * k - 1;
            break;
        case (3): case (5):
            j = 3 * k + 1;
            break;
        case (4):
            j = 4 * k - 1;
            break;
        case (6): case (7): case (8):
            j = k - 2;
            break;
        default:
            cout << "You did not inpupt an integer between 1 and 8" << endl;
    }

    cout << "j: " << j << endl;
}
