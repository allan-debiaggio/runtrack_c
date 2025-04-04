#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les informations d'une chanson
typedef struct Song {
    char *artist;
    char *title;
    int year;
    struct Song *next;
} Song;

// Fonction pour créer une nouvelle chanson
Song *create_song(const char *artist, const char *title, int year) {
    Song *new_song = (Song *)malloc(sizeof(Song));
    if (!new_song) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_song->artist = strdup(artist);
    new_song->title = strdup(title);
    new_song->year = year;
    new_song->next = NULL;
    return new_song;
}

// Fonction pour ajouter une chanson à la liste
void add_song(Song **head, Song *new_song) {
    if (!*head) {
        *head = new_song;
    } else {
        Song *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_song;
    }
}

// Fonction pour libérer la mémoire de la liste
void free_list(Song *head) {
    while (head) {
        Song *temp = head;
        head = head->next;
        free(temp->artist);
        free(temp->title);
        free(temp);
    }
}

// Fonction pour lire le fichier et créer la liste chaînée
Song *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "File not found.\n");
        exit(EXIT_FAILURE);
    }

    Song *head = NULL;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *artist = strtok(line, ",");
        char *title = strtok(NULL, ",");
        char *year_str = strtok(NULL, ",\n");

        if (!artist || !title || !year_str) {
            fprintf(stderr, "Incorrect format.\n");
            fclose(file);
            free_list(head);
            exit(EXIT_FAILURE);
        }

        int year = atoi(year_str);
        add_song(&head, create_song(artist, title, year));
    }

    fclose(file);
    return head;
}

// Fonction de comparaison pour trier par artiste
int compare_artist(const void *a, const void *b) {
    return strcmp((*(Song **)a)->artist, (*(Song **)b)->artist);
}

// Fonction de comparaison pour trier par titre
int compare_title(const void *a, const void *b) {
    return strcmp((*(Song **)a)->title, (*(Song **)b)->title);
}

// Fonction de comparaison pour trier par année
int compare_year(const void *a, const void *b) {
    return (*(Song **)a)->year - (*(Song **)b)->year;
}

// Fonction pour trier la liste
void sort_list(Song **head, const char *method) {
    // Compter les éléments
    int count = 0;
    for (Song *current = *head; current; current = current->next) {
        count++;
    }

    // Copier les éléments dans un tableau
    Song **array = malloc(count * sizeof(Song *));
    if (!array) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    for (Song *current = *head; current; current = current->next) {
        array[i++] = current;
    }

    // Trier le tableau
    if (strcmp(method, "artist") == 0) {
        qsort(array, count, sizeof(Song *), compare_artist);
    } else if (strcmp(method, "title") == 0) {
        qsort(array, count, sizeof(Song *), compare_title);
    } else if (strcmp(method, "year") == 0) {
        qsort(array, count, sizeof(Song *), compare_year);
    } else {
        fprintf(stderr, "Sort method does not exist.\n");
        free(array);
        exit(EXIT_FAILURE);
    }

    // Recréer la liste chaînée
    *head = array[0];
    Song *current = *head;
    for (i = 1; i < count; i++) {
        current->next = array[i];
        current = current->next;
    }
    current->next = NULL;

    free(array);
}

// Fonction pour afficher la liste
void print_list(Song *head) {
    for (Song *current = head; current; current = current->next) {
        printf("\"%s\" by \"%s\" released in %d.\n", current->title, current->artist, current->year);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <sort_method>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *method = argv[2];

    Song *songs = read_file(filename);
    sort_list(&songs, method);
    print_list(songs);

    free_list(songs);
    return EXIT_SUCCESS;
}