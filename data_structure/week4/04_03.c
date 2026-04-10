#include <stdio.h>

int main() {
  int N, mat[100][100];

  scanf("%d", &N);

  int num = 1;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < N; j++) {
        mat[i][j] = num++;
      }
    } else {
      for (int j = N - 1; j >= 0; j--) {
        mat[i][j] = num++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf(" %d", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}