#include <stdio.h>

char *my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest - (src - dest);
}

int main() {
    char source[] = "Hello, World!";
    char destination[50];

    my_strcpy(destination, source);
    printf("Copied string: %s\n", destination);

    return 0;
}
