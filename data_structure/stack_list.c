#include <stdio.h>
#include <stdlib.h>

typedef struct Node {   // 연결리스트로 구현하기 위한 노드 구조체
    char elem;
    struct Node *next;
} Node;

typedef struct {    // 스택 구조체
    Node *top;      // top 위치에 있는 노드
} Stack;

void initStack(Stack *S) {  // 스택 초기화
    S->top = NULL;  // top Node를 Null로 초기화
}

// 연결리스트는 isFull이 없음

int isEmpty(Stack *S) {	// 스택이 비어 있을 때
    return (S->top == NULL);	// 스택의 top 위치에 있는 노드가 NULL이면 비어있음
}

void push(Stack *S, char e) {	// 스택 마지막에 원소 추가(addLast)
    Node *p = (Node *) malloc(sizeof(Node));	// 노드 동적할당
    p->elem = e;								// 노드 초기화(1)
    p->next = S->top;							// 노드 초기화(2) - 연결리스트 가장 앞에 새로운 노드 추가
    S->top = p;									// top을 새로운 노드로 바꿔주기
}

char pop(Stack *S) {	// 스택 마지막에 있는 원소 삭제(deleteLast)
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return (0);
    }

    char e = S->top->elem;	// 반환해줄 원소 저장
	Node *p = S->top;		// 삭제해줄 노드 저장
	S->top = S->top->next;	// top 바꿔주기
	free(p);				// 노드 삭제
	return (e);				// 원소 반환
}

char top(Stack *S) {	// 스택 제일 위에 있는 원소 반환(실습문제에는 peek)
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return (0);
    }

    return (S->top->elem);	// top 위치에 있는 원소 반환
}

int main() {

    return (0);
}