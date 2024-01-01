#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int R = 0;
        char arr [100];
        scanf("%d %s", &R, arr);


        for (int j = 0; arr[j] != '\0'; j++)
        {
            for (int k = 0; k < R; k++)
            {
                printf("%c", arr[j]);
            }
        }

        printf("\n");

    }

    return 0;
}