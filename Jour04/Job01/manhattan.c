#include "manhattan.h"
#include <stdio.h>

int manhattan(struct point p1, struct point p2) {
    return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}

int main() {
    struct point p1 = {3, 4};
    struct point p2 = {1, 1};
    printf("Manhattan distance: %d\n", manhattan(p1, p2));
    return 0;
}
