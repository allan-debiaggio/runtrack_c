#include <stdio.h>

struct album {
    char title[100];
    char artist[100];
    int year;
};

void print_album(struct album *a) {
    if (a != NULL) {
        printf("\"%s\" by \"%s\" released in %d.\n", a->title, a->artist, a->year);
    }
}

int main() {
    struct album my_album = {"Master of Puppets", "Metallica", 1986};
    print_album(&my_album);
    return 0;
}
