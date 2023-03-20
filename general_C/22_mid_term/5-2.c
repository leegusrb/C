#include <stdio.h>

int is_mid_vowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int chk_mid(char a, char b, char c)
{
	return ((a <= b && b <= c) || (a >= b && b >= c));
}

int chk_same(char a, char b, char c)
{
	return (a == b && b == c);
}

int chk_dic(char *T, char a, char b, char c)
{
	return (a <= T[0] && b <= T[1] && c <= T[2]);
}

int main()
{
	char C1, C2, T[4], res[4];
	int flag = 0, chk = 0;

	scanf("%c%c-%s", &C1, &C2, T);

	for (char i = C1; i <= C2; i++)
	{
		for (char j = C1; j <= C2; j++)
		{
			for (char k = C1; k <= C2; k++)
			{
				if (is_mid_vowel(j) && chk_mid(i, j, k) && !chk_same(i, j, k))
				{
					printf("%c%c%c\n", i, j, k);
					flag = 1;
					if (chk_dic(T, i, j, k))
					{
						res[0] = i;
						res[1] = j;
						res[2] = k;
						chk = 1;
					}
				}
			}
		}
	}
	res[3] = '\0';

	if (!flag)
		printf("none\n");
	if (chk)
		printf("%s\n", res);
	else
		printf("none\n");

	return (0);
}