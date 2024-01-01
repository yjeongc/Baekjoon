#include <stdio.h>

int main()
{
    int num1 = 0;
    scanf("%d", &num1);

    for (int i = 0; i < num1; i++)
    {
        for (int j = num1 - i; j > 1; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i+1; k++)
        {
            printf("*");
        }
        
        printf("\n");
    }
     

    return 0;
}