#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a;
    scanf("%d", &a);

    int *arr = (int *)malloc(sizeof(int) * a);
    
    for(int i = 0; i<a; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int j = 0; j<a; j++)
    {
        printf("%d", arr[j]);
    }

    free(arr);


    return 0;
}