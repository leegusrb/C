#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int prev;
  scanf("%d", &prev);

  int res = prev;
  for (int i = 0; i < N - 1; i++) {
    int cur;
    scanf("%d", &cur);

    res = (cur > prev) ? res + cur : res - cur;

    res = (cur % 3 == 0) ? res * 2 : (cur % 2 == 0) ? res + 5 : res;

    prev = cur;
  }

  printf("%d\n", res);

  return 0;
}