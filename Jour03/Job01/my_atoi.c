#include <stdio.h>

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip whitespace characters
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f') {
        i++;
    }

    // Check for optional sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Convert characters to integer
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() {
    const char *test_str = "  -12345";
    int result = my_atoi(test_str);
    printf("Converted integer: %d\n", result);
    return 0;
}
