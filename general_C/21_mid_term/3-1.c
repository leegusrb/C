#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int num, sum = 0;
        scanf("%d", &num);
        int tmp = num;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        printf("%d %d\n", num, sum);
    }

    return (0);
}