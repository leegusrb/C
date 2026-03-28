#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int N, A[50], a, b;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d %d", &a, &b);

  swap(&A[a], &A[b]);

  for (int i = 0; i < N; i++) {
    printf(" %d", A[i]);
  }

  return 0;
}