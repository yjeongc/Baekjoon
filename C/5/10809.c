#include <stdio.h>

int main()
{
    char S[100] = {0,};
    char ABC[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int S2[26];
    scanf("%s", S);


    for (int i = 0; i < 26; i++)
    {
        S2[i] = -1;
    }


    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (ABC[j] == S[i])
            {
                S2[j] = (S2[j] == -1) ? i : S2[j];
            }
        }
    }


    for (int k = 0; k < 26; k++)
    {
        printf("%d ", S2[k]);
    }

    return 0;
}