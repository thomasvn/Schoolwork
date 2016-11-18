#include <iostream>
#include <time.h>
using namespace std;

// Only a copy of the integer x would be incremented
void passByValue(int x) {
    x++;
    return;
}

// The value that was passed would actually be incremented
void passByReference(int& x) {
    x++;
    return;
}

int main() {
    int x = 5;
    passByValue(x);
    cout << "Pass by Value: " << x << endl;

    int y = 5;
    passByReference(y);
    cout << "Pass by Reference: " << y << endl;
}
