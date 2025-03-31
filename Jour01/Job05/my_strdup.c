#include <stdlib.h>
#include <stdio.h>

char *my_strdup(const char *src) {

    const char *temp = src;
    size_t length = 0;
    while (*temp++) {
        length++;
    }


    char *copy = (char *)malloc((length + 1) * sizeof(char));
    if (!copy) {
        return NULL;
    }


    char *dest = copy;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';

    return copy;
}

int main() {
    const char *original = "Hello, World!";
    char *copy = my_strdup(original);

    if (copy) {
        printf("Original: %s\n", original);
        printf("Copy: %s\n", copy);
        free(copy);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
