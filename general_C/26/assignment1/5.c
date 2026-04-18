#include <stdio.h>

int main() {
  char ch;
  int n;

  scanf("%c %d", &ch, &n);

  if (ch >= 'A' && ch <= 'Z')
    ch = 'A' + (ch - 'A' + n) % 26;
  else if (ch >= 'a' && ch <= 'z')
    ch = 'a' + (ch - 'a' + n) % 26;

  printf("%c\n", ch);
  return 0;
}