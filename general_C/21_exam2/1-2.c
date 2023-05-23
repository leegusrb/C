#include <stdio.h>

int main() {
	int room[101] = {0}, roomNum[101], N, M, rn, pn;
	char c;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		roomNum[i] = i;

	while (1) {
		getchar();
		scanf("%c", &c);
		if (c == 'n') break;

		scanf("%d %d", &rn, &pn);
		if (rn > N || pn > M)
			printf("please input correctly\n");
		else if (room[rn] != 0)
			printf("please select another room\n");
		else {
			room[rn] = pn;
			for (int i = 1; i <= N; i++)
				printf("%d ", room[i]);
			printf("\n");
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (room[i] > room[j] || (room[i] == room[j] && roomNum[i] < roomNum[j])) {
				int tmp = room[i];
				room[i] = room[j];
				room[j] = tmp;

				tmp = roomNum[i];
				roomNum[i] = roomNum[j];
				roomNum[j] = tmp;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (room[i] == 0) break;
		printf("%d %d\n", roomNum[i], room[i]);
	}

	return (0);
}