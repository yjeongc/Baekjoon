#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}


int GetParentIDX(int idx)
{
    return idx / 2;
}


int GetLChildIDX(int idx)  //왼쪽 자식 노드의 인덱스 값 반환
{
    return idx * 2;
}


int GetRChildIDX(int idx) //오른쪽 자식 노드의 인덱스 값 반환
{
    return GetLChildIDX(idx) + 1;
}


int GetHiPriChildIDX(Heap* ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData) //왼쪽 자식 노드가 현재 힙에 존재하지 않는 경우. 
        return 0;


    else if (GetLChildIDX(idx) == ph->numOfData) //왼쪽 자식 노드가 힙의 마지막 노드인 경우.
        return GetLChildIDX(idx);


    else
    {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)],  //두 자식 노드의 우선순위를 비교한다.
                     ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap* ph, HData data)
{
    int idx = ph->numOfData + 1;  // 삽입될 데이터의 인덱스 초기화. 힙의 마지막 노드 다음에 데이터를 삽입하도록 인덱스를 설정함.

    // 힙에 새로운 데이터를 삽입하는 과정
    while (idx != 1)
    {
        // 부모 노드의 우선순위와 비교하여 새로운 데이터의 우선순위가 작다면
        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
        {
            // 부모 노드의 데이터를 현재 위치로 이동.
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx); // 현재 위치를 부모 노드의 위치로 갱신
        }
        else
            break; // 우선순위가 적절한 위치를 찾았으므로 반복문 종료
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드를 가져옴

    int parentIdx = 1;
    int childIdx;

    // 삭제된 데이터를 대체할 적잘한 위치를 찾는 과정
    while ((childIdx = GetHiPriChildIDX(ph, parentIdx)) != 0)
    {
        // 마지막 노드의 우선순위와 비교하여 올바른 위치를 찾았으면 종료
        if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;

        // 현재 위치에 자식 노드의 데이터를 이동
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx; // 현재 위치를 자식 노드이 위치로 갱신
    }

    //마지막 노드의 데이터를 삭제된 위치에 삽입
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1; // 힙의 데이터 수 감소
    return retData; // 삭제된 데이터 반환
}