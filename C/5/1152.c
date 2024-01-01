#include <stdio.h>
#include <string.h>

int main()
{
    char S[100];
    int count = 0;
    fgets(S, 100, stdin);

    for (int i = 0; S[i] != '\0'; i++ )
    {
        if (S[i] == ' ')
        {
            count++;
        }
    }


    if (S[0] != ' ' && S[strlen(S)-2] != ' ')
    {
        printf("%d", count+1);
    }
    else if (S[0] == ' ' && S[strlen(S)-2] != ' ')
    {
        printf("%d", count);
    }
    else if (S[0] != ' ' && S[strlen(S)-2] == ' ')
    {
        printf("%d", count);
    }
    else if (S[0] == ' ' && S[strlen(S)-2] == ' ')
    {
        printf("%d", count-1);
    }


    return 0;
}