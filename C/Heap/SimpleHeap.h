#ifndef __SIMPLE_HEAP_H__ 
#define __SIMPLE_HEAP_H__

// 매크로 가드: 이 헤더 파일이 중복으로 포함되지 않도록 하는 역할
// __SIMPLE_HEAP_H__는 임의의 식별자로, 헤더 파일 이름과 관련있는 것이어야 함
// 이 식별자가 이미 정의되어 있다면 아래의 내용이 무시됨

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

// HData와 Priority에 대한 자료형 정의
typedef char HData;
typedef int Priority;

// 힙의 요소를 나타내는 구조체 HeapElem 정의
typedef struct _heapElem
{
    Priority pr;  // 값이 작을수록 높은 우선순위
    HData data;
} HeapElem;

// 힙 자료구조를 나타내는 구조체 Heap 정의
typedef struct _heap
{
    int numOfData;  // 힙에 저장된 데이터의 수
    HeapElem heapArr[HEAP_LEN];  // 힙을 구성하는 배열
} Heap;

// 힙 초기화 함수 선언
void HeapInit(Heap * ph);

// 힙이 비어 있는지 확인하는 함수
int HIsEmpty(Heap *ph);

// 힙에 데이터를 삽입하는 함수
void HInsert(Heap *ph, HData data, Priority pr);

// 힙에서 데이터를 삭제하고 반환하는 함수
HData HDelete(Heap *ph);

// 헤더 파일의 끝을 나타내는 #endif
#endif