#include <stdio.h>

int main() {
  int s1, s2, s3, s4, s5;

  scanf("%d %d %d %d %d", &s1, &s2, &s3, &s4, &s5);

  double avg = (s1 + s2 + s3 + s4 + s5) / 5.0;
  char grade;

  if (avg >= 85) {
    grade = 'A';
  } else if (avg >= 70) {
    grade = 'B';
  } else {
    grade = 'F';
  }

  printf("%c\n%.2f\n", grade, avg);

  return 0;
}