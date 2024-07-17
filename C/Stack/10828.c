#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 1000

//노드의 정보가 담긴 구조체를 선언함.
 typedef struct node{
    int data;
    struct node *link; //다음 노드를 가리키는 포인터
 }Node;
 

 //스택의 top과 크기를 나타내는 포인터
 typedef struct{
   Node *top;
   int size; //스택의 크기를 저장함.
 }Stack;


//스택이 비어있는지 확인하는 함수.
int empty(Stack *s) {
    return (s->top == NULL);
}


//push함수
void push(int x, Stack *s){
    Node *temp = (Node *)malloc(sizeof(Node)); //새로운 노드를 만든다.
    temp->data = x; //새로운 노드에 데이터 넣기.
    temp->link = s->top;
    s->top = temp;
    s->size++;
}


//pop함수
int pop(Stack *s){
    if(empty(s) == 1)
        return -1;
    else{
        Node *temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        s->size--;
        free(temp);
        return data;
    }
}


//스택에 들어있는 정수의 개수를 출력한다.
int size(Stack *s){
    return s->size;
}


//스택의 가장 위에 있는 정수를 출력한다.
int top(Stack *s){
    if(empty(s) == 1)
        return -1;
    else{
        return s->top->data;
    }
}

typedef struct{
    char command[MAX_COMMAND_LEN];
    int arg; //push의 인자를 받을 때 사용함.
}Command;


int main(){
    int N;
    scanf("%d", &N);

    Command commands[N];
    Stack stack;
    stack.top = NULL;
    stack.size = 0;
    
    
    
    for(int i=0; i<N; i++){
        scanf("%s", commands[i].command);
        if(strcmp(commands[i].command, "push") == 0){
            scanf("%d", &commands[i].arg);
        }
    }

    for(int j=0; j<N; j++){
        if(strcmp(commands[j].command, "push") == 0){
            push(commands[j].arg, &stack);
        }
        else if(strcmp(commands[j].command, "pop") == 0){
            printf("%d\n",pop(&stack));
        }
        else if(strcmp(commands[j].command, "size") == 0){
            printf("%d\n",size(&stack));
        }
        else if(strcmp(commands[j].command, "empty") == 0){
            printf("%d\n", empty(&stack));
        }
        else if(strcmp(commands[j].command, "top") == 0){
            printf("%d\n", top(&stack));
        }
    }


    return 0;
}