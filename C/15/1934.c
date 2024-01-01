#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++)
    {
        int num1, num2;
        int m, lcm;
        scanf("%d %d", &num1, &num2);

        for (int j = 1; j<=num1 && j<=num2; ++j){
            if (num1%j == 0 && num2%j == 0)
            m = j;
        }

        lcm = (num1 * num2) / m;
        printf("%d\n",lcm);
    }
    return 0;
}