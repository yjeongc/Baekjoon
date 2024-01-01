#include <stdio.h>
#include <string.h>

int main()
{
    int num1 = 0, num2 = 0;
    char A[4], B[4];
    char A_result[4], B_result[4];
    scanf("%s %s", A, B);

    for (int i = 2; i>-1; i--)
    {
        A_result[num1] = A[i];
        num1++;
    }
    A_result[num1] = '\0';
    

    for (int i = 2; i>-1; i--)
    {
        B_result[num2] = B[i];
        num2++;
    }
    B_result[num2] = '\0';


    if (strcmp(A_result, B_result) > 0)
        printf("%s", A_result);
    else if (strcmp(A_result, B_result) < 0)
        printf("%s", B_result);

    return 0;
}