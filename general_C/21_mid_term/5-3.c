#include <stdio.h>

int main()
{
    int N, cnt = 0, max = 0, lastPrime, maxN, minN;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int num, isPrime = 1;
        scanf("%d", &num);
        if (num <= 1 || num >= 100)
            isPrime = 0;
        else
        {
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime)
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt;
                lastPrime = num;
            }
        }
        else
            cnt = 0;

        if (i == 0)
        {
            maxN = num;
            minN = num;
        }
        else
        {
            if (maxN < num)
                maxN = num;
            if (minN > num)
                minN = num;
        }
    }

    if (max == 0)
        printf("0\n");
    else
        printf("%d\n%d\n%d %d\n", max, lastPrime, maxN, minN);

    return (0);
}