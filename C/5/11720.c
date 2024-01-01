#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, sum = 0;
    scanf("%d", &N);

    char *arr = (char *)malloc(sizeof(char) * N+1);  //Null을 위한 공간.
    scanf("%s", arr);


    for(int i = 0; i < N; i++)
    {
        sum += arr[i] - '0';
    }


    printf("%d", sum);

    free(arr);

    return 0;
}