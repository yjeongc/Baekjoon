#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    double max = 0, sum = 0;
    scanf("%d", &N);
    double *arr = (double *)malloc(sizeof(double) * N);


    for (int i = 0; i < N; i++)
    {
        int num1 = 0;
        scanf("%d", &num1);
        arr[i] = num1;
    }

    max = arr[0];


    for (int j = 1; j < N + 1; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
        }
    }


    for (int k = 0; k < N; k++)
    {
        arr[k] = (arr[k]/max)*100;
    }

    
    for (int l = 0; l < N; l++)
    {
        sum += arr[l];
    }

    printf("%f", sum/N);      

    return 0;
}