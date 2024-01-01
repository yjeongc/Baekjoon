#include <stdio.h>

int main ()
{
    int num1 = 0, num2 = 0;
    scanf("%d", &num1);
    num2 = num1/4;

    for (int i = 0; i<num2; i++)
    {
        printf("long ");
    }

    printf("int");

    return 0;
}