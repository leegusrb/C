#include <stdio.h>

int main() {
  int N, arr[100];

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  int changeN, changeArr[100];

  scanf("%d", &changeN);

  for (int i = 0; i < changeN; i++) {
    scanf("%d", &changeArr[i]);
  }

  for (int i = 1; i < changeN; i++) {
    int tmp = arr[changeArr[0]];
    arr[changeArr[0]] = arr[changeArr[i]];
    arr[changeArr[i]] = tmp;
  }

  for (int i = 0; i < N; i++) {
    printf(" %d", arr[i]);
  }

  return 0;
}