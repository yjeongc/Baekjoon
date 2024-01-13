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

int main()
{
    int N, i;
    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    BubbleSort(arr, N);

    for (i=0; i<N; i++)
        printf("%d ", arr[i]);


    return 0;
}