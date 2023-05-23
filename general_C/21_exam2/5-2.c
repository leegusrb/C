#include <stdio.h>

int prime_number(int num) {
	if (num == 1)
		return (0);

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return (0);
	}
	return (1);
}

int odd_number(int num) {
	while (num > 0) {
		if (num % 2 == 0)
			return (0);
		num /= 10;
	}
	return (1);
}

int count_number(int cnt, int num) {
	if (prime_number(num) && odd_number(num))
		return (cnt + 1);
	return (0);
}

int main() {
	int X[100], num, n = 0, cnt = 0, max = 0, idx = 0;

	while (1) {
		scanf("%d", &num);
		if (num <= 0) break;

		if (prime_number(num) || odd_number(num))
			X[n++] = num;
	}

	for (int i = 0; i < n; i++) {
		cnt = (count_number(cnt, X[i]));
		if (cnt > max) {
			max = cnt;
			idx = i;
		}
	}

	if (max == 0)
		printf("0\n");
	else {
		for (int i = idx - max + 1; i <= idx; i++)
			printf("%d ", X[i]);
		printf("\n");
	}

	return (0);
}