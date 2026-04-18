#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int is_odd = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    if (num % 2 == 0) {
      if (is_odd == 1)
        sum += num;
      is_odd = 0;
    } else {
      is_odd = 1;
    }
  }

  printf("%d\n", sum);

  return 0;
}