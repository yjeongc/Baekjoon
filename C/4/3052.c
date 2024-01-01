#include <stdio.h>

int main()
{
    int arr[10] = {0,};
    int result = 0;

    for (int i = 0; i< 10; i++)
    {
        int num1 = 0;
        scanf("%d", &num1);
        arr[i] = num1%42;
    }


    for (int j = 0; j < 10; j++)
    {
        int count = 0;
        for (int k = 1; k < 10; k++)
        {
            if (arr[j] == arr [k])
            {
                count++;
            }
        }
    }

    return 0;
}