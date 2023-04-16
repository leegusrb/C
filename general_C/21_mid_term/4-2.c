#include <stdio.h>

int main()
{
    int maxN, max = 0, minN, min = 0;
    while (1)
    {
        int num, tot = 0;
        scanf("%d", &num);
        if (num <= 1) break;
        int tmp = num;
        for (int i = 2; i <= tmp; i++)
        {
            int cnt = 0;
            while (tmp % i == 0)
            {
                cnt++;
                tmp /= i;
            }
            if (cnt != 0)

            {
                printf("%d %d ", i, cnt);
                tot++;
            }
        }
        printf("\n");
        if (max == 0 || tot > max || (tot == max && num < maxN))
        {
            max = tot;
            maxN = num;
        }
        if (min == 0 || tot < min || (tot == min && num > minN))
        {
            min = tot;
            minN = num;
        }
    }
    printf("%d %d\n", maxN, minN);

    return (0);
}