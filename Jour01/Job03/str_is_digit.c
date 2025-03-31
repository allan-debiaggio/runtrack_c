#include <stdio.h>

int char_is_digit(char c);

int str_is_digit(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!char_is_digit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}


int main() {
    char test_char = '5';
    const char *test_str1 = "12345";
    const char *test_str2 = "123a5";

    printf("Is '%c' a digit? %d\n", test_char, char_is_digit(test_char));

    printf("Is \"%s\" a digit-only string? %d\n", test_str1, str_is_digit(test_str1));
    printf("Is \"%s\" a digit-only string? %d\n", test_str2, str_is_digit(test_str2));

    return 0;
}
