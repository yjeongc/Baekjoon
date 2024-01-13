#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;

    if (pointA->y == pointB->y) {
        return pointA->x - pointB->x;
    } else {
        return pointA->y - pointB->y;
    }
}

int main() {
    int N, i;
    scanf("%d", &N);

    Point *points = (Point *)malloc(sizeof(Point) * N);

    for (i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, N, sizeof(Point), compare);

    for (i = 0; i < N; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);

    return 0;
}