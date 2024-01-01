#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    int *arr = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }


    for (int k = 0; k < M; k++)
    {
        int i = 0, j = 0;
        scanf("%d %d", &i, &j);

        int num1 = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1] = num1;
    }


    for (int l = 0; l < N; l++)
    {
        printf("%d ", arr[l]);
    }


    return 0;
}