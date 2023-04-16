#include <stdio.h>

int main()
{
    char max = 0, min = 0;
    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '0')  break;
        else if (c >= 'a' && c <= 'z')
        {
            if (max == 0 || c > max)
                max = c;
        }
        else
        {
            if (min == 0 || c < min)
                min = c;
        }
    }
    if (max != 0)
        printf("%c", max);
    if (min != 0)
        printf("%c", min);
    printf("\n");

    return (0);
}