#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **array_clone(char **array, int n) {
    if (!array || n <= 0) {
        return NULL;
    }

    // Allocate memory for the output array (n + 1 for NULL terminator)
    char **clone = malloc((n + 1) * sizeof(char *));
    if (!clone) {
        return NULL;
    }

    int i;
    for (i = 0; i < n && array[i] != NULL; i++) {
        // Allocate memory for each string and copy it
        clone[i] = malloc(strlen(array[i]) + 1);
        if (!clone[i]) {
            // Free already allocated memory in case of failure
            for (int j = 0; j < i; j++) {
                free(clone[j]);
            }
            free(clone);
            return NULL;
        }
        strcpy(clone[i], array[i]);
    }

    // Set the last element to NULL
    clone[i] = NULL;

    return clone;
}

int main() {
    // Example usage of array_clone
    char *array[] = {"Hello", "World", "!", NULL};
    int n = 3;

    char **clone = array_clone(array, n);
    if (clone) {
        for (int i = 0; clone[i] != NULL; i++) {
            printf("%s\n", clone[i]);
            free(clone[i]);
        }
        free(clone);
    }

    return 0;
}
