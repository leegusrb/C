#include <stdio.h>

int main() {
  int N, arr[100];

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  int revN;

  scanf("%d", &revN);

  for (int i = 0; i < revN; i++) {
    int start, end;
    scanf("%d %d", &start, &end);

    for (int j = start, k = end; j < k; j++, k--) {
      int tmp = arr[j];
      arr[j] = arr[k];
      arr[k] = tmp;
    }
  }

  for (int i = 0; i < N; i++) {
    printf(" %d", arr[i]);
  }

  return 0;
}