#include <stdio.h>

int main()
{
	char maxU = 'A', maxL = 'a', minU = 'Z', minL = 'z';

	while (1)
	{
		char c;
		scanf("%c", &c);
		if (c == '!') break;

		if (c >= 'a' && c <= 'z')
		{
			if (c > maxL)
				maxL = c;
			if (c < minL)
				minL = c;
		}

		if (c >= 'A' && c <= 'Z')
		{
			if (c > maxU)
				maxU = c;
			if (c < minU)
				minU = c;
		}
	}

	if (minU - 'A' > minL - 'a')
		printf("%c\n", minL);
	else
		printf("%c\n", minU);

	if (maxU - 'A' <= maxL - 'a')
		printf("%c\n", maxL);
	else
		printf("%c\n", maxU);

	return 0;
}