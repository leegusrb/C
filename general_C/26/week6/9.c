#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int ce_cnt = 0, sw_cnt = 0, ds_cnt = 0;
  int ce_clean = 0, sw_clean = 0, ds_clean = 0;
  int has_error = 0;

  for (int i = 0; i < N; i++) {
    int pw;
    scanf("%d", &pw);

    if (pw < 10000 || pw > 99999) {
      printf("none1\n");
      has_error = 1;
      continue;
    }

    if (pw % 100 != 0) {
      printf("none2\n");
      has_error = 1;
      continue;
    }

    int d1 = pw / 10000;
    int d2 = pw / 1000 % 10;
    int d3 = pw / 100 % 10;

    if (d3 > 5) {
      printf("none3\n");
      has_error = 1;
      continue;
    }

    int cnt_same = (d1 == d2) + (d2 == d3) + (d3 == d1);

    if (cnt_same != 1) {
      printf("none4\n");
      has_error = 1;
      continue;
    }

    if (d3 <= 2) {
      printf("CE\n");
      if (!has_error) {
        ce_clean++;
      }
      ce_cnt++;
    } else if (d3 <= 4) {
      printf("SW\n");
      if (!has_error) {
        sw_clean++;
      }
      sw_cnt++;
    } else {
      printf("DS\n");
      if (!has_error) {
        ds_clean++;
      }
      ds_cnt++;
    }

    has_error = 0;
  }

  printf("%d %d %d\n", ce_cnt, sw_cnt, ds_cnt);
  printf("%d %d %d\n", ce_clean, sw_clean, ds_clean);

  return 0;
}