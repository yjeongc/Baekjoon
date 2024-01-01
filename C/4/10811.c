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

        int start = i -1;
        int end = j -1;

        while (start < end)
        {
            int num1 = arr[start];
            arr[start] = arr[end];
            arr[end] = num1;
            start++;
            end--;
        }
    } 


    for (int l = 0; l < N; l++)
    {
        printf("%d ", arr[l]);
    }

    free(arr);

    return 0;
}