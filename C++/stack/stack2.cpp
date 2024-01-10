#include <iostream>

using namespace std;

struct Stack{
    int N = -1; // 스택의 현재 상태. -1은 스택이 비어있음.
    int * arr;
};
using stack = Stack *; //stack 포인터에 대한 별칭

//스택이 비어있는지 확인함.
bool empty(stack s){
    return (s->N == -1) ? true : false;
}

//스택에 추가하는 함수
void push (stack s, int num){
    s->arr[++s->N] = num;
}

//스택에서 제거하는 함수
void pop (stack s){
    if(empty(s)){
        cout << "It doesn't work. stack is empty" << "\n";
    }
    else{
        s->N--; //top을 하나 감소해서 값을 제거함.
    }
}

//스택의 top 값을 반환함.
int top(stack s){
    if(empty(s)){
        return -1; 
    }
    return s->arr[s->N];
}

//스택의 크기를 반환함.
int size(stack s){
    return s->N+1;
}

int main(){

    stack myStack = new Stack();

    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);

    cout << "Top is : " << top(myStack) << "\n";

    pop(myStack);
    cout << "Top element after pop: " << top(myStack) << "\n";

    // 메모리 해제
    delete myStack;

    return 0;
}