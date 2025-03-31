#include <unistd.h>

void my_putchar(char character)
{
    write(1, &character, 1);
}