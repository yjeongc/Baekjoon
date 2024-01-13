#include <stdio.h>
#include <stdlib.h>

// 배열에서 최댓값을 찾는 함수
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 기수 정렬을 위한 계수 정렬 함수
void countingSort(int arr[], int n, int exp) {
    const int BASE = 10; // 10진법을 기준으로 정렬

    int* output = (int*)malloc(n * sizeof(int));
    int* count = (int*)malloc(BASE * sizeof(int));

    // 초기화
    for (int i = 0; i < BASE; i++) {
        count[i] = 0;
    }

    // 각 자릿수별 빈도수 계산
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }

    // 빈도수 누적합 계산
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }

    // output 배열에 정렬된 순서대로 값 저장
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    // 원래 배열에 정렬된 값을 복사
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // 동적 할당한 메모리를 해제
    free(output);
    free(count);
}

// 기수 정렬 함수
void radixSort(int arr[], int n) {
    // 배열에서 최댓값 찾기
    int max = findMax(arr, n);

    // 자릿수 별로 counting sort 수행
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// 배열 출력 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
