#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 1; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      for (int k = j; k <= 6; k++) {
        if (i + j + k == N) {
          printf("%d %d %d\n", i, j, k);
        }
      }
    }
  }

  return 0;
}