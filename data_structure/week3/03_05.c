#include <stdio.h>

void hanoi(int N, char from, char aux, char to) {
  if (N == 1) {
    printf("%c %c\n", from, to);
    return;
  }

  hanoi(N - 1, from, to, aux);
  printf("%c %c\n", from, to);
  hanoi(N - 1, aux, from, to);
}

int main() {
  int N;

  scanf("%d", &N);

  hanoi(N, 'A', 'B', 'C');

  return 0;
}