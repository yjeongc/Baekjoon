#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

typedef struct _node
{
    LData data;  //노드에 저장된 데이터.
    struct _node* next;  //다음 노드를 가리키는 포인터.
} Node;


//이중 연결 리스트를 나타내는 구조체 정의
typedef struct _linkedList
{
    Node* head;  //리스트의 첫 번째 노드를 가리키는 포인터
    Node* cur;  //리스트에서 현재 위치를 가리키는 포인터
    Node* before;  //현재 위치 이전의 노드를 가리키는 포인터
    int numOfData;  //리스트에 저장된 데이터의 수
    int (*comp) (LData d1, LData d2);  //정렬을 위한 비교함수를 가리키는 함수 포인터
} LinkedList;


typedef LinkedList List;


void ListInit(List* plist);  //이중 연결 리스트를 초기화 하는 함수
void LInsert(List* plist, LData data);  //새로운 노드를 리스트에 삽입하는 함수

int LFirst(List* plist, LData* pdata); //리스트에서 첫 번째 노드의 데이터를 가져오는 함수
int LNext(List* plist, LData* pdata);  //리스트에서 다음 노드와 데이터를 가져오는 함수


LData LRemove(List* plist); //현재 노드를 삭제하고 데이터를 반환하는 함수
int LCount(List* plist); //리스트에 저장된 노드의 수를 반환하는 함수


void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)); //리스트의 정렬 규칙을 설정하는 함수

#endif