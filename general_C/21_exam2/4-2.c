#include <stdio.h>

int main() {
	int M, ar[51], sort[5], res[51];
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &ar[i]);
	}

	if (M % 2 == 0)
		printf("Invalid Input\n");
	else {
		for (int i = 0; i < M; i++) {
			if (i < 2 || i >= M - 2)
				res[i] = ar[i];
			else {
				for (int j = 0; j < 5; j++)
					sort[j] = ar[i - 2 + j];

				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < j; k++) {
						if (sort[j] > sort[k]) {
							int tmp = sort[j];
							sort[j] = sort[k];
							sort[k] = tmp;
						}
					}
				}

				res[i] = sort[2];
			}
		}

		for (int i = 0; i < M; i++)
			printf(" %d", res[i]);
		printf("\n");
	}

	return (0);
}