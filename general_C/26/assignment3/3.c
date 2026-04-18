#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int in_segment = 0, cnt = 0;

  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    int is_prime = 1;
    if (num < 2)
      is_prime = 0;
    for (int j = 2; j < num; j++) {
      if (num % j == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime) {
      if (!in_segment) {
        printf("%d ", num);
        cnt++;
        in_segment = 1;
      }
    } else {
      in_segment = 0;
    }
  }

  printf("\n%d\n", cnt);

  return 0;
}