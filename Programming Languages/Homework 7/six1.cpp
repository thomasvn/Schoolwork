#include <iostream>
using namespace std;

int main() {
    int first, second, third;
    int max, mid, min;

    cout << "Enter first number: ";
    cin >> first;
    cout << "Enter second number: ";
    cin >> second;
    cout << "Enter third number: ";
    cin >> third;

    if (first > second && first > third) {
        if (second > third) {
            max = first;
            mid = second;
            min = third;
        }
        else {
            max = first;
            mid = third;
            min = second;
        }
    }
    if (second > first && second > third) {
        if (first > third) {
            max = second;
            mid = first;
            min = third;
        }
        else {
            max = second;
            mid = third;
            min = first;
        }
    }
    if (third > first && third > second) {
        if (first > second) {
            max = third;
            mid = first;
            min = second;
        }
        else {
            max = third;
            mid = second;
            min = third;
        }
    }

    cout << "Max: " << max << endl;
    cout << "Mid: " << mid << endl;
    cout << "Min: " << min << endl;
}
