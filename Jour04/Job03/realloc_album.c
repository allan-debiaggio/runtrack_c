#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    int year;
} Album;

Album* realloc_album(Album* albums, size_t current_size, size_t new_size) {
    if (new_size == 0) {
        free(albums);
        return NULL;
    }

    Album* new_albums = (Album*)malloc(new_size * sizeof(Album));
    if (!new_albums) {
        perror("Failed to allocate memory");
        return NULL;
    }

    size_t copy_size = current_size < new_size ? current_size : new_size;
    for (size_t i = 0; i < copy_size; i++) {
        new_albums[i] = albums[i];
    }

    free(albums);
    return new_albums;
}

int main() {
    size_t current_size = 2;
    Album* albums = (Album*)malloc(current_size * sizeof(Album));
    if (!albums) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Initialize albums
    strcpy(albums[0].title, "Album 1");
    strcpy(albums[0].artist, "Artist 1");
    albums[0].year = 2001;

    strcpy(albums[1].title, "Album 2");
    strcpy(albums[1].artist, "Artist 2");
    albums[1].year = 2002;

    // Print current albums
    printf("Current albums:\n");
    for (size_t i = 0; i < current_size; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", albums[i].title, albums[i].artist, albums[i].year);
    }

    // Resize albums
    size_t new_size = 3;
    albums = realloc_album(albums, current_size, new_size);
    if (!albums) {
        return 1;
    }

    // Initialize new album
    strcpy(albums[2].title, "Album 3");
    strcpy(albums[2].artist, "Artist 3");
    albums[2].year = 2003;

    // Print updated albums
    printf("\nUpdated albums:\n");
    for (size_t i = 0; i < new_size; i++) {
        printf("Title: %s, Artist: %s, Year: %d\n", albums[i].title, albums[i].artist, albums[i].year);
    }

    // Free memory
    free(albums);
    return 0;
}
