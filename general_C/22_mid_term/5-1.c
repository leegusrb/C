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

int main()
{
	char start, end;
	int flag = 0;

	scanf("%c%c", &start, &end);

	for (char i = start; i <= end; i++)
	{
		for (char j = start; j <= end; j++)
		{
			for (char k = start; k <= end; k++)
			{
				if (is_mid_vowel(j) && chk_mid(i, j, k) && !chk_same(i, j, k))
				{
					printf("%c%c%c\n", i, j, k);
					flag = 1;
				}
			}
		}
	}

	if (!flag)
		printf("none\n");
}