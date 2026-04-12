#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
  char elem;
  struct Term *next;
} Node;

typedef struct {
  // 단일 연결 리스트는 트레일러 노드가 없음
  Node *H;
  int n;
} List;

void init(List *L) {
  // 헤더 노드 생성
  L->H = (Node *)malloc(sizeof(Node));

  // 헤더 노드 초기화
  L->H->next = NULL;

  // 리스트 크기 초기화
  L->n = 0;
}

void add(List *L, int r, char e) {
  if (r < 1 || r > L->n + 1) {
    printf("invalid position\n");
    return;
  }

  Node *cur = L->H;

  // 추가할 노드의 전 노드 위치 찾기
  // (추가할 노드의 위치 까지 가면 되돌아 올 수 없기 때문)
  for (int i = 0; i < r - 1; i++) {
    cur = cur->next;
  }

  // 새로운 노드 생성
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->elem = e;

  // 새로운 노드 연결
  newNode->next = cur->next;

  // 이전 노드와 다음 노드 연결
  cur->next = newNode;

  // 리스트 크기 증가
  L->n++;
}

void delete(List *L, int r) {
  if (r < 1 || r > L->n) {
    printf("invalid position\n");
    return;
  }

  Node *cur = L->H;

  // 삭제할 노드의 전 노드 위치 찾기
  for (int i = 0; i < r - 1; i++) {
    cur = cur->next;
  }

  Node *delNode = cur->next;

  // 삭제할 노드 연결 해제
  cur->next = delNode->next;

  // 메모리 해제
  free(delNode);

  // 리스트 크기 감소
  L->n--;
}

char get(List *L, int r) {
  if (r < 1 || r > L->n) {
    printf("invalid position\n");
    return '\0';
  }

  Node *cur = L->H;

  // 원하는 노드 찾기
  for (int i = 0; i < r; i++) {
    cur = cur->next;
  }

  return cur->elem;
}

void print(List *L) {
  Node *cur = L->H->next;

  while (cur != NULL) {
    printf("%c", cur->elem);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  List L;
  init(&L);

  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    char cmd;
    scanf(" %c", &cmd);

    if (cmd == 'A') {
      int r;
      char e;
      scanf("%d %c", &r, &e);
      add(&L, r, e);
    } else if (cmd == 'D') {
      int r;
      scanf("%d", &r);
      delete(&L, r);
    } else if (cmd == 'G') {
      int r;
      scanf("%d", &r);
      char e = get(&L, r);
      if (e != '\0') {
        printf("%c\n", e);
      }
    } else if (cmd == 'P') {
      print(&L);
    }
  }

  return 0;
}