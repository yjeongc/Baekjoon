#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    int *arr = (int *)malloc(sizeof(int) * N );

    for (int i = 0; i < N; i++)
    {
        arr[i] = 0;
    }
    
    
    for (int j = 0; j < M; j++)
    {
        int num1 = 0, num2 = 0, num3 = 0;
        scanf("%d %d %d", &num1, &num2, &num3);

        for (int k = num1; k < num2 + 1; k++)
        {
            arr[k-1] = num3;
        }

    }
    
    
    for (int l = 0; l < N; l++)
    {
        printf("%d ", arr[l]);
    }

    return 0;
}