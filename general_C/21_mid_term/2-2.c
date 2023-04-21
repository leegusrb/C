#include <stdio.h>

int main()
{
    char max = 0, min = 0, first = 0;
    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '0')  break;
        if (first == 0)
            first = c;
        if (c >= 'a' && c <= 'z')
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
    if (max != 0 && min != 0)
    {
        if (first >= 'a' && first <= 'z')
            printf("%c%c", max, min);
        else
            printf("%c%c", min, max);
    }
    else if (max != 0)
        printf("%c", max);
    else
        printf("%c", min);
    printf("\n");

    return (0);
}
