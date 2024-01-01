#include <stdio.h>

int main()
{
    int num1 = 0, A = 0, B = 0;
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }    

    return 0;
}