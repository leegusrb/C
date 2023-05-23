#include <stdio.h>

int main() {
	char str[100], c;
	int n = 0, cnt = 0;

	while (1) {
		scanf("%c", &c);
		if (c == '*') break;

		if (c >= 'a' && c <= 'z')
			str[n++] = c - 'a' + 'A';
		else if (c >= 'A' && c <= 'Z')
			str[n++] = c - 'A' + 'a';
	}

	for (int i = 0; i < n; i++) {
		if (i < n - 2 &&
			(str[i] >= 'A' && str[i] <= 'Z' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') &&
			(str[i + 1] == 'a' || str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'o' || str[i + 1] == 'u') &&
			(str[i + 2] >= 'a' && str[i + 2] <= 'z' && str[i + 2] != 'a' && str[i + 2] != 'e' && str[i + 2] != 'i' && str[i + 2] != 'o' && str[i + 2] != 'u'))
			cnt++;
		printf("%c", str[i]);
	}
	printf("\n");

	printf("%d\n", cnt);

	return (0);
}