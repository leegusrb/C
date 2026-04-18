#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int prev = 0;
  int cur_len = 1;
  int seg_cnt = 0, max_len = 0;

  for (int i = 0; i < N; i++) {
    int cur;
    scanf("%d", &cur);

    if (prev * cur > 0) {
      cur_len++;
    } else {
      if (cur_len >= 2 && prev != 0) {
        seg_cnt++;
        if (cur_len > max_len)
          max_len = cur_len;
      }
      cur_len = 1;
    }
    prev = cur;
  }

  if (cur_len >= 2 && prev != 0) {
    seg_cnt++;
    if (cur_len > max_len)
      max_len = cur_len;
  }

  printf("%d %d\n", seg_cnt, max_len);

  return 0;
}