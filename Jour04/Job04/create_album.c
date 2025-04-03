#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for an album
typedef struct Album {
    char *artist;
    char *title;
    int release_year;
    struct Album *next;
} Album;

// Function to create a new album
Album *create_album(const char *artist, const char *title, int release_year) {
    Album *new_album = (Album *)malloc(sizeof(Album));
    if (new_album == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    new_album->artist = strdup(artist);
    new_album->title = strdup(title);
    new_album->release_year = release_year;
    new_album->next = NULL;

    return new_album;
}

// Main function to test create_album
int main() {
    Album *album = create_album("Artist Name", "Album Title", 2023);

    if (album != NULL) {
        printf("Album created:\n");
        printf("Artist: %s\n", album->artist);
        printf("Title: %s\n", album->title);
        printf("Release Year: %d\n", album->release_year);

        // Free allocated memory
        free(album->artist);
        free(album->title);
        free(album);
    }

    return 0;
}
