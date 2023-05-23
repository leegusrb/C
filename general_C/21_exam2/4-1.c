#include <stdio.h>

int main() {
	int M, ar[51], res[51];

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
		scanf("%d", &ar[i]);

	if (M % 2 == 0)
		printf("Invalid Input\n");
	else {
		for (int i = 0; i < M; i++) {
			if (i < 2 || i > M - 3)
				res[i] = ar[i];
			else {
				double s = 0;
				for (int j = i - 2; j <= i + 2; j++)
					s += ar[j];
				res[i] = s / 5 + 0.5;
			}
		}

		for (int i = 0; i < M; i++)
			printf(" %d", res[i]);
		printf("\n");
	}

	return (0);
}