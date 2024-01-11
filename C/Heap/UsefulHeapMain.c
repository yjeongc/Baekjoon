#include <stdio.h>
#include "UsefulHeap.h"


int DataPriorityComp(char ch1, char ch2) // 우선순위 비교 함수
{
    return ch2 - ch1;
}


int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);  //힙의 초기화

    HInsert(&heap, 'A');  //문자 'A'를 최고의 우선순위로 저장
    HInsert(&heap, 'B');  //문자 'B'를 두번째 우선순위로 저장
    HInsert(&heap, 'C');  //문자 'C'를 두번째 우선순위로 저장
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    while (!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));


    return 0;
}