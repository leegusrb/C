#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int odd_rev = 0, even_rev = 0;

  while (N > 0) {
    int num = N % 10;
    if (num % 2 == 1) {
      odd_rev = odd_rev * 10 + num;
    } else {
      even_rev = even_rev * 10 + num;
    }
    N /= 10;
  }

  printf("%d %d\n", even_rev, odd_rev);

  return 0;
}