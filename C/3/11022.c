#include <stdio.h>

int main()
{
    int num1 = 0;
    scanf("%d", &num1);

    for (int i = 1; i < num1+1; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        printf("Case \#%d: %d + %d = %d\n", i,A,B, A+B);
    }

    return 0;
}