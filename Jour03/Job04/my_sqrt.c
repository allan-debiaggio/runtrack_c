#include <stdio.h>

int my_sqrt(int n) {
    if (n < 0) return 0; // Negative numbers don't have integer square roots
    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }
    return 0; // Return 0 if no integer square root is found
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    int result = my_sqrt(number);
    if (result) {
        printf("The integer square root of %d is %d.\n", number, result);
    } else {
        printf("%d does not have an integer square root.\n", number);
    }

    return 0;
}
