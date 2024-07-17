#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 1000

//����� ������ ��� ����ü�� ������.
 typedef struct node{
    int data;
    struct node *link; //���� ��带 ����Ű�� ������
 }Node;
 

 //������ top�� ũ�⸦ ��Ÿ���� ������
 typedef struct{
   Node *top;
   int size; //������ ũ�⸦ ������.
 }Stack;


//������ ����ִ��� Ȯ���ϴ� �Լ�.
int empty(Stack *s) {
    return (s->top == NULL);
}


//push�Լ�
void push(int x, Stack *s){
    Node *temp = (Node *)malloc(sizeof(Node)); //���ο� ��带 �����.
    temp->data = x; //���ο� ��忡 ������ �ֱ�.
    temp->link = s->top;
    s->top = temp;
    s->size++;
}


//pop�Լ�
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


//���ÿ� ����ִ� ������ ������ ����Ѵ�.
int size(Stack *s){
    return s->size;
}


//������ ���� ���� �ִ� ������ ����Ѵ�.
int top(Stack *s){
    if(empty(s) == 1)
        return -1;
    else{
        return s->top->data;
    }
}

typedef struct{
    char command[MAX_COMMAND_LEN];
    int arg; //push�� ���ڸ� ���� �� �����.
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