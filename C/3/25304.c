#include <stdio.h>

int main()
{
    int num1 = 0, n = 2, num3 = 0;
    scanf("%d", &num1);
    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        int num4 = 0, num5 = 0;
        scanf("%d %d", &num4, &num5);

        num3 += num4*num5;
    }

    if (num1 == num3)
        printf("Yes");
    else
        printf("No");

    return 0;
}