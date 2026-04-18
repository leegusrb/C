#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int upper_max = 0, lower_max = 0;
  char upper_letter, lower_letter;

  for (int i = 0; i < N; i++) {
    int upper = 0, lower = 0, num = 0;
    char first_letter = '\0';

    getchar();
    while (1) {
      char c;
      scanf("%c", &c);

      if (first_letter == '\0')
        first_letter = c;

      if (c == '*')
        break;

      if (c >= 'A' && c <= 'Z')
        upper++;
      else if (c >= 'a' && c <= 'z')
        lower++;
      else if (c >= '0' && c <= '9')
        num++;

      if (upper > upper_max) {
        upper_max = upper;
        upper_letter = first_letter;
      }
      if (lower > lower_max) {
        lower_max = lower;
        lower_letter = first_letter;
      }
    }

    printf("%d %d %d\n", upper, lower, num);
  }

  printf("%c %c\n", upper_letter, lower_letter);

  return 0;
}