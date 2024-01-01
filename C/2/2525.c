#include <stdio.h>

int main ()
{
    int H = 0, M = 0, TM = 0;
    scanf("%d %d", &H, &M);
    scanf("%d", &TM);

    M += TM;

    while (M >= 60)
    {
        M -= 60;
        H += 1;
    }
    if (H >= 24)
        H -= 24;

    printf("%d %d", H, M);

    return 0;
}