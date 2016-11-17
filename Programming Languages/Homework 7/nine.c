#include <stdio.h>

int main() {
    int x, y;

    printf("Enter a number for x: ");
    scanf("%d", &x);

    if (x > 10) {
        y = x;
    }
    if (x < 5) {
        y = 2 * x;
    }
    if (x == 7) {
        y = x + 10;
    }

    printf("y: %d \n", y);
}
