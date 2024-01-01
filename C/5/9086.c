#include <stdio.h>
#include <string.h>

int main()
{
    int num1 = 0;
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++)
    {
        char arr[1000];
        scanf("%s", arr);

        printf("%c%c\n", arr[0], arr[strlen(arr)-1]);
    }

    return 0;
}