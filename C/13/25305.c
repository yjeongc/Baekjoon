#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n){
    int i, j;
    int temp;

    for (i = 0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if (arr[j] < arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int i = 0, N = 0, k = 0;
    scanf("%d %d", &N, &k);

    int *arr = (int *)malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    BubbleSort(arr, N);

    printf("%d", arr[k-1]);


    return 0;
}