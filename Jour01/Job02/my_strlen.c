#include <unistd.h>

// Function to calculate the length of a string
int my_strlen(char *str) 
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}


void my_putnbr(int n) {
    if (n >= 10) {
        my_putnbr(n / 10); 
    }
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(void)
{
    int length = my_strlen("Hello, World !");
    my_putnbr(length); 
    write(1, "\n", 1); 
    return 0;
}