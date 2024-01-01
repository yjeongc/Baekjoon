#include<stdio.h>

int main()
{
    int A = 0, B = 0;
    
    while(scanf("%d %d", &A, &B) != EOF)
    {
        if (scanf("%*s") == EOF)  // "%*s"는 문자열을 읽어들이지만 저장하지 않는 형식. 입력버퍼에서 문자열을 제거할 수 있다.
            break;
        printf("%d\n", A+B);
    }

    return 0;
}