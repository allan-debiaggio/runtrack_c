#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the album structure
typedef struct Album {
    char title[100];
    struct Album *next;
} Album;

// Function to push an album to the front of the list
void push_front_album(Album **head, Album new_album) {
    Album *new_node = (Album *)malloc(sizeof(Album));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->title, new_album.title);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the album list
void print_album_list(Album *head) {
    Album *current = head;
    while (current != NULL) {
        printf("%s\n", current->title);
        current = current->next;
    }
}

// Main function to demonstrate the functionality
int main() {
    Album *album_list = NULL;

    Album album1 = {"Album 1", NULL};
    Album album2 = {"Album 2", NULL};
    Album album3 = {"Album 3", NULL};

    push_front_album(&album_list, album1);
    push_front_album(&album_list, album2);
    push_front_album(&album_list, album3);

    printf("Album list:\n");
    print_album_list(album_list);

    // Free the allocated memory
    Album *current = album_list;
    while (current != NULL) {
        Album *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}