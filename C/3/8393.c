#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0;
    scanf("%d", &num1);

    for (int i = 1; i < num1+1; i++)
    {
        num2 += i;
    }

    printf("%d", num2);

    return 0;
}