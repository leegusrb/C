#include <stdio.h>

int main() {
  char ch;
  char first_char = 0;
  char max_lower = 0, min_upper = 0;

  while (1) {
    scanf("%c", &ch);
    if (ch == '0')
      break;

    if (first_char == 0)
      first_char = ch;

    if (ch >= 'a' && ch <= 'z') {
      if (max_lower == 0 || ch > max_lower)
        max_lower = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      if (min_upper == 0 || ch < min_upper)
        min_upper = ch;
    }
  }

  if (min_upper == 0) {
    printf("%c\n", max_lower);
  } else if (max_lower == 0) {
    printf("%c\n", min_upper);
  } else if (first_char >= 'a' && first_char <= 'z') {
    printf("%c%c\n", max_lower, min_upper);
  } else {
    printf("%c%c\n", min_upper, max_lower);
  }

  return 0;
}