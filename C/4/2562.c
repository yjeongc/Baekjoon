#include <stdio.h>

int main()
{
    int arr[9] = {0,};
    int max = 0, index = 0;

    for (int i = 0; i < 9; i++)
    {
        int num1 = 0;
        scanf("%d", &num1);
        arr[i] = num1;
    }

    max = arr[0];
    for (int j = 0; j < 9; j++)
    {
        if ( max < arr[j])
        {
            max = arr[j];
            index = j;
        }
    }

    printf("%d\n", max);
    printf("%d", index + 1);

    return 0;
}