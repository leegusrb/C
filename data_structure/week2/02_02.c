#include <stdio.h>

int mostOnes(int A[][100], int n) {
  int row = 0, maxIdx = 0;
  for (int i = 0; i < n; i++) {
    while (A[i][row] == 1) {
      row++;
      maxIdx = i;
    }
  }
  return maxIdx;
}

int main() {
  int A[100][100];
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("%d", mostOnes(A, n));

  return 0;
}