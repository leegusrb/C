#include <stdio.h>

int main() {
	int room[11] = {0}, rn, pn;
	char c;

	while (1) {
		scanf("%c", &c);
		if (c == 'n') break;

		scanf("%d %d", &rn, &pn);
		if (rn > 10 || pn > 4)
			printf("please input correctly\n");
		else if (room[rn] != 0)
			printf("please select another room\n");
		else {
			room[rn] = pn;
			for (int i = 1; i <= 10; i++)
				printf("%d ", room[i]);
			printf("\n");
		}
		getchar();
	}

	return (0);
}