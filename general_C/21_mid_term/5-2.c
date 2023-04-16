#include <stdio.h>

int main()
{
    int N, cnt = 0, max = 0, lastPrime;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int num, isPrime = 1;
        scanf("%d", &num);
        if (num == 1 || num >= 100)
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

    }
    
    if (max == 0)
        printf("0\n");
    else
        printf("%d\n%d\n", max, lastPrime);

    return (0);
}