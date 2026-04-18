#include <stdio.h>

int main() {
  int y1, m1, d1, y2, m2, d2, y3, m3, d3;
  scanf("%d/%d/%d %d/%d/%d %d/%d/%d", &y1, &m1, &d1, &y2, &m2, &d2, &y3, &m3,
        &d3);

  int date1 = y1 * 10000 + m1 * 100 + d1;
  int date2 = y2 * 10000 + m2 * 100 + d2;
  int date3 = y3 * 10000 + m3 * 100 + d3;

  int min_y, min_m, min_d;
  if (date1 <= date2 && date1 <= date3) {
    min_y = y1;
    min_m = m1;
    min_d = d1;
  } else if (date2 <= date1 && date2 <= date3) {
    min_y = y2;
    min_m = m2;
    min_d = d2;
  } else {
    min_y = y3;
    min_m = m3;
    min_d = d3;
  }

  printf("%04d/%02d/%02d\n", min_y, min_m, min_d);
  return 0;
}