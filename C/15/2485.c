#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 0;
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int *arr2 = (int *)malloc(sizeof(int) * (size - 1));

    for (int j = 0; j < (size - 1); j++) {
        arr2[j] = arr[j + 1] - arr[j];
    }

    int min = arr2[0];
    for (int k = 0; k < (size - 1); k++) {
        if (arr2[k] < min)
            min = arr2[k];
    }

    int count = 0;
    for (int l = 0; l < (size - 1); l++) {
        if (arr2[l] > min) {
            count += (arr2[l] / min) - 1;
        }
    }

    printf("%d", count);

    free(arr);
    free(arr2);
    return 0;
}
