#include "SimpleHeap.h"

void HeapInit(Heap *ph)  //힙의 초기화
{
    ph -> numOfData = 0; //numOfData는 힙에 저장된 데이터 수
}


int HIsEmpty(Heap * ph) //힙이 비었는지 확인
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;   
}


int GetParentIDX(int idx) // 부모 노드의 인덱스 값 반환
{
    return idx/2;
}


int GetLChildIDX(int idx)  //왼쪽 자식 노드의 인덱스 값 반환
{
    return idx*2;
}


int GetRChildIDX(int idx) //오른쪽 자식 노드의 인덱스 값 반환
{
    return GetLChildIDX(idx)+1;
}


//두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData) //왼쪽 자식 노드가 현재 힙에 존재하지 않는 경우. 
    //이후 코드에서 왼쪽 자식과 오른쪽 자식 중 우선순위가 높은 자식을 선택하기 위해서 왼쪽 자식 노드가 힙에 존재하지 않는 경우에도 비교한다.
        return 0; //이 노드에 자식이 없음.
    else if (GetLChildIDX(idx) == ph->numOfData) //왼쪽 자식 노드가 힙의 마지막 노드인 경우.
        return GetLChildIDX(idx);
    else
    {
        if(ph->heapArr[GetLChildIDX(idx)].pr  //두 자식 노드의 우선순위를 비교한다.
            > ph ->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}


//힙에 데이터 저장
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph -> numOfData+1;  // 삽입될 데이터의 인덱스 초기화. 힙의 마지막 노드 다음에 데이터를 삽입하도록 인덱스를 설정함.
    HeapElem nelem = {pr, data}; // 새로운 힙 요소 생성.

    // 힙에 새로운 데이터를 삽입하는 과정
    while(idx !=1)
    {
        // 부모 노드의 우선순위와 비교하여 새로운 데이터의 우선순위가 작다면
        if(pr < (ph-> heapArr[GetParentIDX(idx)].pr))
        {
                // 부모 노드의 데이터를 현재 위치로 이동.
            ph -> heapArr[idx] = ph -> heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx); // 현재 위치를 부모 노드의 위치로 갱신
        }
        else
            break; // 우선순위가 적절한 위치를 찾았으므로 반복문 종료
    }

    ph -> heapArr[idx] = nelem; // 최종적으로 새로운 데이터를 삽입
    ph -> numOfData += 1; //힙의 데이터 수 증가
}


// 힙에서 데이터 삭제
HData HDelete(Heap *ph)
{
    HData retData = (ph -> heapArr[1]).data; // 삭제될 데이터의 반환을 위해 저장
    HeapElem lastElem = ph -> heapArr[ph->numOfData]; // 힙의 마지막 노드를 가져옴

    int parentIdx = 1;
    int childIdx;

    // 삭제된 데이터를 대체할 적잘한 위치를 찾는 과정
    while((childIdx = GetHiPriChildIDX(ph, parentIdx)) != 0)
    {
        // 마지막 노드의 우선순위와 비교하여 올바른 위치를 찾았으면 종료
        if(lastElem.pr <= ph -> heapArr[childIdx].pr)
            break;

        // 현재 위치에 자식 노드의 데이터를 이동
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx; // 현재 위치를 자식 노드이 위치로 갱신
    }

    //마지막 노드의 데이터를 삭제된 위치에 삽입
    ph -> heapArr[parentIdx] = lastElem;
    ph -> numOfData -= 1; // 힙의 데이터 수 감소
    return retData; // 삭제된 데이터 반환
}

