#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  double avg = (a + b + c) / 3.0;

  int below70_cnt = (a < 70) + (b < 70) + (c < 70);
  int has_100 = (a == 100 || b == 100 || c == 100);

  char grade;
  if (below70_cnt >= 2 && !has_100) {
    grade = 'F';
  } else {
    if (avg >= 85)
      grade = 'A';
    else if (avg >= 70)
      grade = 'B';
    else
      grade = 'F';
  }

  printf("%c\n%.2f\n", grade, avg);
  return 0;
}