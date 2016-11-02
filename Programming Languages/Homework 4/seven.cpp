#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void staticArray() {
    char staticArr[100000];
}

void dynamicArray() {
    new char[100000];
}

void timeTest(string array) {
    string strA ("staticArray");
    string strB ("dynamicArray");

    clock_t start;
    double duration;

    for (int i = 0; i < 100000; i++) {
        if (array.compare(strA) == 0) {
            staticArray();
        } else if (array.compare(strB) == 0) {
            dynamicArray();
        } else {
            cout << "Error. Proper array name not passed" << endl;
            break;
        }
    }
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    if (array.compare(strA) == 0) {
        cout << "Static Array Duration: ";
    } else if (array.compare(strB) == 0) {
        cout << "Dynamic Array Duration: ";
    }
    cout << duration << " seconds" << endl;
}

int main() {
    string str1 ("staticArray");
    string str2 ("dynamicArray");

    timeTest(str1);
    timeTest(str2);
}
