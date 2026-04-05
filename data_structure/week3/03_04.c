#include <stdio.h>

int max(int A[], int N) {
  if (N == 1)
    return A[0];

  int mx = max(A, N - 1);

  if (A[N - 1] > mx)
    return A[N - 1];
  else
    return mx;
}

int main() {
  int N, A[100];

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  printf("%d\n", max(A, N));

  return 0;
}