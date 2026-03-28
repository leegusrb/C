#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[8];
  int kor;
  int math;
  int eng;
  float avg;
} Student;

int main() {
  int N;
  Student *S;

  scanf("%d", &N);

  S = (Student *)malloc(N * sizeof(Student));

  for (int i = 0; i < N; i++) {
    scanf("%s %d %d %d", S[i].name, &S[i].kor, &S[i].math, &S[i].eng);
    S[i].avg = (S[i].kor + S[i].math + S[i].eng) / 3.0;
  }

  for (int i = 0; i < N; i++) {
    printf("%s %.1f ", S[i].name, S[i].avg);

    if (S[i].kor >= 90 || S[i].math >= 90 || S[i].eng >= 90) {
      printf("GREAT ");
    }

    if (S[i].kor < 70 || S[i].math < 70 || S[i].eng < 70) {
      printf("BAD ");
    }

    printf("\n");
  }

  return 0;
}