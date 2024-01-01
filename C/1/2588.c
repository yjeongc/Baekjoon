#include <stdio.h>

int main()
{
    int num1 = 0, num2 = 0;
    int num3 = 0,num4 = 0, num5 = 0, num6 = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);

    num3 = num1*((num2%100)%10);
    num4 = num1*((num2/10)%10);
    num5 = num1*(num2/100);
    num6 = num3 + num4*10 + num5*100;
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);
    printf("%d", num6);
    
    return 0;
}