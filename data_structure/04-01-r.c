#include <stdio.h>

void reverse(int *ar, int start, int end)
{
    if (start >= end)
        return;

    int tmp = ar[start];
    ar[start] = ar[end];
    ar[end] = tmp;
    reverse(ar, start + 1, end - 1);
}

int main()
{
    int N, ar[100];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &ar[i]);

    int revN;
    scanf("%d", &revN);
    for (int i = 0; i < revN; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        reverse(ar, start, end);
    }

    for (int i = 0; i < N; i++)
        printf(" %d", ar[i]);
    printf("\n");

    return (0);
}
