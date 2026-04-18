#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int flag = 0;

  for (int i = 1; i <= 6; i++) {
    for (int j = i; j <= 6; j++) {
      for (int k = j; k <= 6; k++) {
        int is_odd = (i % 2 == 1) + (j % 2 == 1) + (k % 2 == 1);
        if (i + j + k == N && is_odd == 2) {
          printf("%d %d %d\n", i, j, k);
          flag = 1;
        }
      }
    }
  }

  if (!flag) {
    printf("0\n");
  }

  return 0;
}