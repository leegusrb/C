#include <stdio.h>

int main()
{
    while (1)
    {
        int num;
        scanf("%d", &num);
        if (num <= 1) break;
        for (int i = 2; i <= num; i++)
        {
            int cnt = 0;
            while (num % i == 0)
            {
                cnt++;
                num /= i;
            }
            if (cnt != 0)
                printf("%d %d ", i, cnt);
        }
        printf("\n");
    }

    return (0);
}