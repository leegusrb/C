#include <stdio.h>

int main() {
  int N, M, mat[100][100];

  scanf("%d %d", &N, &M);

  int num = 1;
  for (int i = 0; i < M; i++) {
    int x = 0;
    int y = i;

    while (x < N && y >= 0) {
      mat[x++][y--] = num++;
    }
  }

  for (int i = 1; i < N; i++) {
    int x = i;
    int y = M - 1;

    while (x < N && y >= 0) {
      mat[x++][y--] = num++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf(" %d", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}