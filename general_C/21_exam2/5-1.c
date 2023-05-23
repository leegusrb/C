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

int main() {
	int X[100], num, cnt = 0;

	while (1) {
		scanf("%d", &num);
		if (num <= 0) break;

		if (prime_number(num) || odd_number(num))
			X[cnt++] = num;
	}

	if (cnt == 0)
		printf("0\n");
	else {
		for (int i = cnt - 1; i >= 0; i--)
			printf("%d ", X[i]);
		printf("\n");
	}

	return (0);
}