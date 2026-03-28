#include <stdio.h>
#include <string.h>

int main() {
  char str[101];

  scanf("%s", str);

  int len = (int)strlen(str);
  for (int i = 0; i < len; i++) {
    printf("%s\n", str);

    char temp = str[0];
    for (int j = 0; j < len - 1; j++) {
      str[j] = str[j + 1];
    }
    str[len - 1] = temp;
  }

  return 0;
}