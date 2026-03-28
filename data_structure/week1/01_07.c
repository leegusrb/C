#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  int *A1, *A2;

  scanf("%d", &N);

  A1 = (int *)malloc(N * sizeof(int));
  A2 = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    scanf("%d", &A1[i]);
  }

  for (int i = 0; i < N; i++) {
    scanf("%d", &A2[i]);
  }

  for (int i = 0; i < N; i++) {
    printf(" %d", A1[i] + A2[N - 1 - i]);
  }

  return 0;
}