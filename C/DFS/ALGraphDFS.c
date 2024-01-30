#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);


//그래프의 초기화
void GraphInit(ALGraph* pg, int nv)
{

    int i;

    pg->adjList = (List*)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;  //초기의 간선 수는 0개

    for (i = 0; i < nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->vistiInfo = (int*)malloc(sizeof(int) * pg->numV);
    memset(pg->vistiInfo, 0, sizeof(int) * pg->numV);
}


//그래프 리소스의 해제
void GraphDestroy(ALGraph* pg)
{
    if (pg->adjList != NULL)
        free(pg->adjList);

    if (pg->vistiInfo != NULL)
        free(pg->vistiInfo);
}


//간선 추가
void AddEdge(ALGraph* pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}


//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
    int i;
    int vx;


    for (i = 0; i < pg->numV; i++)
    {
        printf("%c와 연결된 정점: ", i + 65);

        if (LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx + 65);

            while (LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx + 65);
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if (data1 < data2)
        return 0;
    else
        return 1;
}


int VisitVertex(ALGraph* pg, int visitV)
{
    if (pg->vistiInfo[visitV] == 0)
    {
        pg->vistiInfo[visitV] = 1;

        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}


void DFShowGraphVertex(ALGraph* pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        int visitFlag = FALSE;

        if (VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if (VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if (visitFlag == FALSE)
        {
            if (SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }

    memset(pg->vistiInfo, 0, sizeof(int) * pg->numV);
}

