#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an album
typedef struct Album {
    char title[100];
    struct Album* next;
} Album;

// Function to add an album to the end of the list
void push_back_album(Album** head, const char* title) {
    // Create a new album node
    Album* new_album = (Album*)malloc(sizeof(Album));
    if (new_album == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(new_album->title, title);
    new_album->next = NULL;

    // If the list is empty, set the new album as the head
    if (*head == NULL) {
        *head = new_album;
        return;
    }

    // Traverse to the end of the list
    Album* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Add the new album at the end
    current->next = new_album;
}

// Function to print the list of albums
void print_albums(Album* head) {
    Album* current = head;
    while (current != NULL) {
        printf("Album: %s\n", current->title);
        current = current->next;
    }
}

// Main function to test push_back_album
int main() {
    Album* album_list = NULL;

    // Add albums to the list
    push_back_album(&album_list, "Album 1");
    push_back_album(&album_list, "Album 2");
    push_back_album(&album_list, "Album 3");

    // Print the list of albums
    printf("List of albums:\n");
    print_albums(album_list);

    // Free the allocated memory
    Album* current = album_list;
    while (current != NULL) {
        Album* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}