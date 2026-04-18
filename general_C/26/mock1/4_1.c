#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    int is_prime = 1;
    if (num <= 1) {
      is_prime = 0;
    } else {
      for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) {
          is_prime = 0;
          break;
        }
      }
    }

    if (is_prime) {
      if (cnt == 3) {
        printf("*\n");
        cnt = 0;
      }
      printf("%d ", num);
      cnt++;
    }
  }

  printf("*\n");

  return 0;
}