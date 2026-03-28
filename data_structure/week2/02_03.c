#include <stdio.h>
#include <stdlib.h>

int *prefixAverages1(int *X, int n) {
  int *A;
  A = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += X[j];
    }
    A[i] = (int)((double)sum / (i + 1) + 0.5);
  }

  return A;
}

int *prefixAverages2(int *X, int n) {
  int *A;
  A = (int *)malloc(n * sizeof(int));

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += X[i];
    A[i] = (int)((double)sum / (i + 1) + 0.5);
  }

  return A;
}

int main() {
  int n;
  int *X;

  scanf("%d", &n);

  X = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &X[i]);
  }

  int *A1 = prefixAverages1(X, n);
  int *A2 = prefixAverages2(X, n);

  for (int i = 0; i < n; i++) {
    printf(" %d", A1[i]);
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf(" %d", A2[i]);
  }
  printf("\n");

  return 0;
}