#include <stdio.h>

int main() {
  int N, M;

  scanf("%d %d", &N, &M);

  int mat[100][100];
  int left = 0, right = M - 1, top = 0, bottom = N - 1;

  int cnt = 1;

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; i++) {
      mat[top][i] = cnt++;
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      mat[i][right] = cnt++;
    }
    right--;

    if (left > right || top > bottom)
      break;

    for (int i = right; i >= left; i--) {
      mat[bottom][i] = cnt++;
    }
    bottom--;

    for (int i = bottom; i >= top; i--) {
      mat[i][left] = cnt++;
    }
    left++;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf(" %d", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}