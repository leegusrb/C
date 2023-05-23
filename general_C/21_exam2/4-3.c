#include <stdio.h>

int main() {
	int M, N, ar[51], sort[5], res[51];
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		scanf("%d", &ar[i]);
	}

	if (M * N % 2 == 0 || N >= M)
		printf("Invalid Input\n");
	else {
		for (int i = 0; i < M; i++) {
			if (i < N / 2 || i >= M - N / 2)
				res[i] = ar[i];
			else {
				for (int j = 0; j < N; j++)
					sort[j] = ar[i - N / 2 + j];

				for (int j = 0; j < N; j++) {
					for (int k = 0; k < j; k++) {
						if (sort[j] > sort[k]) {
							int tmp = sort[j];
							sort[j] = sort[k];
							sort[k] = tmp;
						}
					}
				}

				res[i] = sort[N / 2];
			}
		}

		for (int i = 0; i < M; i++)
			printf(" %d", res[i]);
		printf("\n");
	}

	return (0);
}