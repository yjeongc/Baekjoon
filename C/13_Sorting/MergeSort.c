#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left; //왼쪽 부분 배열의 시작 인덱스
    int rIdx = mid+1; // 오른쪽 부분 배열의 시작 인덱스
    int i;

    // 병합 및 정렬된 값을 저장할 임시 배열
    int *sortArr = (int*)malloc(sizeof(int)*right+1);
    int sIdx = left;

    // 두 부분 배열을 비교하여 작은 값을 sortArr에 저장하며 정렬한다.
    while(fIdx <= mid && rIdx <= right) //왼쪽 값이 작다는 건 더 나눌 수 있다는 뜻!
    {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    // 왼쪽 부분 배열에 남은 값이 있는 경우
    if (fIdx > mid)
    {
        for(i=rIdx; i<= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    // 오른쪽 부분 배열에 남은 값이 있는 경우
    else{
        for(i=fIdx; i<=mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    // 정렬된 값을 다시 원래 배열에 복사한다.
    for(i=left; i <=right; i++)
        arr[i] = sortArr[i];

    //동적 할당한 메모리를 해제한다.
    free(sortArr);
}


void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        //중간 지점을 계산한다.
        mid = (left+right) / 2;

        //둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        //정렬된 두 배열을 병합한다.
        MergeTwoArea(arr, left, mid, right);
    }
}


int main()
{
    int arr[7] = {3,2,4,1,7,6,5};
    int i;

    //배열 arr의 전체 영역 정렬
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<7; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}