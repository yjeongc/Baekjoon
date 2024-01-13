#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n){
    int i, j;
    int temp;

    for (i = 0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int Average(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i<n; i++)
    {
        sum += arr[i];
    }
    return sum/5;
}

int main()
{
    int i = 0, N = 5;

    int *arr = (int *)malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    BubbleSort(arr, N);
    int average = Average(arr, N);

    printf("%d\n", average);
    printf("%d", arr[N/2]);


    return 0;
}