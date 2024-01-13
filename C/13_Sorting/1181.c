#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단어 구조체 정의
struct Word {
    char str[51];
};

// 문자열 비교 함수
int compare(const void *a, const void *b) {
    // 길이가 짧은 것부터 정렬
    int len_a = strlen(((struct Word*)a)->str);
    int len_b = strlen(((struct Word*)b)->str);

    if (len_a != len_b)
        return len_a - len_b;

    // 길이가 같으면 사전 순으로 정렬
    return strcmp(((struct Word*)a)->str, ((struct Word*)b)->str);
}

int main() {
    int N, i;
    scanf("%d", &N);

    // 단어 구조체 배열 동적 할당
    struct Word *words = (struct Word *)malloc(sizeof(struct Word) * N);

    // 단어 입력 받기
    for (i = 0; i < N; i++) {
        scanf("%s", words[i].str);
    }

    // qsort 함수를 이용하여 정렬
    qsort(words, N, sizeof(struct Word), compare);

    // 중복 제거 및 출력
    for (i = 0; i < N; i++) {
        if (i > 0 && strcmp(words[i].str, words[i - 1].str) == 0)
            continue; // 중복된 단어는 출력하지 않음

        printf("%s\n", words[i].str);
    }

    // 메모리 해제
    free(words);

    return 0;
}
