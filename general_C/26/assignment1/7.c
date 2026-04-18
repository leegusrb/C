#include <stdio.h>

int main() {
  int a, b, c, d, e;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

  double avg = (a + b + c + d + e) / 5.0;

  char grade;
  if (avg >= 85)
    grade = 'A';
  else if (avg >= 70)
    grade = 'B';
  else
    grade = 'F';

  printf("%c %.2f\n", grade, avg);

  int cnt100 = (a == 100) + (b == 100) + (c == 100) + (d == 100) + (e == 100);
  if (cnt100 >= 2)
    printf("Good\n");

  int any_below70 = (a < 70) || (b < 70) || (c < 70) || (d < 70) || (e < 70);
  if (!any_below70 && avg >= 90)
    printf("Excellent\n");

  if (any_below70)
    printf("Bad\n");

  if (e - a >= 30)
    printf("Unbalanced\n");

  return 0;
}