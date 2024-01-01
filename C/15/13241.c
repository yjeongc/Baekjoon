#include <stdio.h>

int main ()
{
    long long int num1, num2;
        long long int m, lcm;
        scanf("%lld %lld", &num1, &num2);

        for (int j = 1; j<=num1 && j<=num2; ++j){
            if (num1%j == 0 && num2%j == 0)
            m = j;
        }

        lcm = (num1 * num2) / m;
        printf("%lld\n",lcm);
    
    return 0;
}