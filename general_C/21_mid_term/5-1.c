#include <stdio.h>

int main()
{
    int N, M, cnt = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        int num, isPrime = 1;
        scanf("%d", &num);
        if (num == 1)
            isPrime = 0;
        for (int j = 2; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
        {
            printf(" %d", num);
            cnt++;
        }
        if (cnt == M) break;
    }
    if (cnt == 0)
        printf("0");
    printf("\n");

    return (0);
}