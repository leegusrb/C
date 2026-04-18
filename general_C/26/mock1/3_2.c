#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int cnt = 0;
  for (int i = 1; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      for (int k = j; k <= 6; k++) {
        int cnt_even = (i % 2 == 0) + (j % 2 == 0) + (k % 2 == 0);
        if (i + j + k == N && cnt_even == 2) {
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