#include <stdio.h>

void ABC(int A[], int k) {
  int maxIdx = k;
  for (int i = k; i < 10; i++) {
    if (A[i] > A[maxIdx]) {
      maxIdx = i;
    }
  }

  int temp = A[k];
  A[k] = A[maxIdx];
  A[maxIdx] = temp;
}

int main() {
  int A[10];

  for (int i = 0; i < 10; i++) {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < 9; i++) {
    ABC(A, i);
  }

  for (int i = 0; i < 10; i++) {
    printf(" %d", A[i]);
  }

  return 0;
}