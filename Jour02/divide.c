#include <stdio.h>

// Function to divide the value of an integer by 2
void divide(int *num) {
    if (num != NULL) {
        *num /= 2;
    }
}

// Example usage
int main() {
    int value = 10;
    printf("Before divide: %d\n", value);
    divide(&value);
    printf("After divide: %d\n", value);
    return 0;
}
