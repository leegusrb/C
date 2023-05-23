#include <stdio.h>

int main() {
	int N, one[20], two[20];
	double avg[20];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &one[i]);

	for (int i = 0; i < N; i++) {
		scanf("%d", &two[i]);
		avg[i] = one[i] * 0.4 + two[i] * 0.6;
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (avg[i] < avg[j])
				rank++;
		}
		printf("%d %d %d %.1lf %d ", i + 1, one[i], two[i], avg[i], rank);
		if (N * 0.7 >= rank || two[i] >= 80)
			printf("P\n");
		else
			printf("F\n");
	}

	return (0);
}