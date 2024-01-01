#include <stdio.h>

int main ()
{
    char S[1000];
    scanf("%s", S);

    int num1 = 0;
    scanf("%d", &num1);

    printf("%c", S[num1-1]);
    
    return 0;
}