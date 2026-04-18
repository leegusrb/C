#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int cnt = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      for (int k = j; k <= 6; k++) {
        if (i + j + k == N) {
          printf("%d %d %d\n", i, j, k);
          cnt++;
        }
      }
    }
  }

  if (cnt == 0) {
    printf("0\n");
  }

  return 0;
}