#include <stdio.h>

int main() {
  char ch;
  char max_lower = 0, min_upper = 0;

  while (1) {
    scanf("%c", &ch);
    if (ch == '0')
      break;

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
  } else {
    printf("%c\n", min_upper);
  }

  return 0;
}