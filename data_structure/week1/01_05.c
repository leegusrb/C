#include <stdio.h>

typedef struct {
  int h;
  int m;
  int s;
} Time;

int main() {
  Time t1, t2;

  scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
  scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

  int total1 = t1.h * 3600 + t1.m * 60 + t1.s;
  int total2 = t2.h * 3600 + t2.m * 60 + t2.s;

  int diff = total2 - total1;

  int h = diff / 3600;
  int m = (diff % 3600) / 60;
  int s = diff % 60;

  printf("%d %d %d", h, m, s);

  return 0;
}