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

    if (first > second && first > third && second > third) {
        max = first;
        mid = second;
        min = third;
    }
    if (first > second && first > third && third > second) {
        max = first;
        mid = third;
        min = second;
    }
    if (second > first && second > third && first > third) {
        max = second;
        mid = first;
        min = third;
    }
    if (second > first && second > third && third > first) {
        max = second;
        mid = third;
        min = first;
    }
    if (third > first && third > second && first > second) {
        max = third;
        mid = first;
        min = second;
    }
    if (third > first && third > second && second > first) {
        max = third;
        mid = second;
        min = first;
    }

    cout << "Max: " << max << endl;
    cout << "Mid: " << mid << endl;
    cout << "Min: " << min << endl;
}
