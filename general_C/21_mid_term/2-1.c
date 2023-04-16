#include <stdio.h>

int main()
{
    char res = 0;

    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '0')  break;
        if (res == 0)
            res = c;
        else if (c >= 'a' && c <= 'z')
        {
            if (c > res)
                res = c;
        }
        else
        {
            if (c < res)
                res = c;
        }
    }
    printf("%c\n", res);

    return (0);
}