#include <stdlib.h>
#include <stdio.h>

char *my_itoa(int num) {
    int temp = num, len = (num <= 0) ? 1 : 0;
    while (temp) {
        temp /= 10;
        len++;
    }

    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str) return NULL;

    str[len] = '\0';
    int is_negative = (num < 0);
    if (is_negative) num = -num;

    for (int i = len - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
        if (is_negative && i == 0) str[i] = '-';
    }

    return str;
}

int main() {
    int number = -12345;
    char *result = my_itoa(number);
    if (result) {
        printf("The string representation of %d is: %s\n", number, result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
