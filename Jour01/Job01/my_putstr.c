#include <unistd.h>

void my_putchar(char character);

void my_putstr(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        my_putchar(string[i]);
        i++;
    }
}

int main() {
    my_putstr("Hello, world !\n");
    return 0;
}