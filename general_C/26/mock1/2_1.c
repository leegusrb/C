#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int pw;
    scanf("%d", &pw);

    if (pw < 10000 || pw > 99999) {
      printf("none\n");
      continue;
    }

    if (pw % 100 != 0) {
      printf("none\n");
      continue;
    }

    int d1 = pw / 10000;
    int d2 = pw / 1000 % 10;
    int d3 = pw / 100 % 10;

    if (d3 > 5) {
      printf("none\n");
      continue;
    }

    int cnt_same = (d1 == d2) + (d2 == d3) + (d3 == d1);

    if (cnt_same != 1) {
      printf("none\n");
      continue;
    }

    if (d3 <= 2) {
      printf("CE\n");
    } else if (d3 <= 4) {
      printf("SW\n");
    } else {
      printf("DS\n");
    }
  }

  return 0;
}