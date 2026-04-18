#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int upper = 0, lower = 0, num = 0;

    getchar();
    while (1) {
      char c;
      scanf("%c", &c);

      if (c == '*')
        break;

      if (c >= 'A' && c <= 'Z')
        upper++;
      else if (c >= 'a' && c <= 'z')
        lower++;
      else if (c >= '0' && c <= '9')
        num++;
    }

    printf("%d %d %d\n", upper, lower, num);
  }

  return 0;
}