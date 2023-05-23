#include <stdio.h>
#include <stdlib.h>

typedef struct {    // 스택 구조체
    char *elems;    // 배열(아직 배열의 크기를 모르기 때문에 포인터로 선언)
    int top;        // 가장 위에 있는 원소의 위치
    int size;       // 배열의 크기
} Stack;

void initStack(Stack *S) {  // 스택 초기화
    scanf("%d", &S->size);  // 배열 크기 입력

    S->elems = (char *) malloc(sizeof(char) * S->size); // 배열 만들기
    S->top = -1;    // 초기 상태의 스택은 top이 -1
}

int isFull(Stack *S) {  // 스택이 다 차있을 때(배열일 때에만 필요)
    return (S->top == S->size - 1);
}

int isEmpty(Stack *S) { // 스택이 비어 있을 때
    return (S->top == -1);
}

void push(Stack *S, char e) {   // 스택 마지막에 원소 추가(addLast)
    if (isFull(S)) {
        printf("Stack FULL\n");
        return ;
    }

    S->top++;               // top + 1
    S->elems[S->top] = e;   // top 위치에 원소 추가
}

char pop(Stack *S) {    // 스택 마지막에 있는 원소 삭제(deleteLast)
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return (0);
    }

    S->top--;                       // top - 1
    return (S->elems[S->top + 1]);  // top + 1(top을 -1 해줬기 때문이) 위치에 있는 원소 반환
}

char top(Stack *S) {    // 스택 제일 위에 있는 원소 반환(실습문제에는 peek)
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return (0);
    }

    return (S->elems[S->top]);  // top 위치에 있는 원소 반환
}

int main() {

    return (0);
}