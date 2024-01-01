#include <stdio.h>

int main()
{
    int H = 0, M = 0, H2 = 0, M2 = 0;
    scanf("%d %d", &H, &M);

    M2 = M - 45;
    H2 = H;
    if (M2 < 0)
        {
          M2 += 60;
            H2 = H-1;  
        }
        
    if (H2 < 0)
        H2 +=24;
    

    printf("%d %d", H2, M2);

    return 0;
}