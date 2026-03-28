#include <stdio.h>

typedef struct {
  char name[10];
  int score;
} Student;

int main() {
  Student S[5];

  for (int i = 0; i < 5; i++) {
    scanf("%s %d", S[i].name, &S[i].score);
  }

  float avg = 0;
  for (int i = 0; i < 5; i++) {
    avg += S[i].score;
  }
  avg /= 5;

  for (int i = 0; i < 5; i++) {
    if (S[i].score <= avg) {
      printf("%s\n", S[i].name);
    }
  }

  return 0;
}